#include "Magnet.h"

Magnet::Magnet(int height, int width)
{
    std::random_device rd;
    std::mt19937 gen(rd());        //Using Mersenne twister
    std::uniform_int_distribution<> distribution(0,1);    //Evenly 0s and 1s

    spins.reserve(height);
    for(int i=0;i<height;i++)
    {
        spins.push_back(std::vector<int>());    //Puts an empty vector on it
        spins[i].reserve(width);
        for(int j=0;j<width;j++)
            spins[i].push_back(distribution(gen));
    }
}

bool Magnet::update(int i,int j)
{
    if(updatePending(i,j))
    {
        spins[i][j] = spins[i][j] == 1 ? -1 : 1;
        return true;
    }
    else
        return false;
}

bool Magnet::isStable(void)
{
    for(int i = 0; i < spins.size(); i++)
        for(int j = 0; j < (spins[i]).size(); j++)
            if(updatePending(i,j))
                return false;
    //If we reach here then there are no updates pending
    return true;
}

bool Magnet::updatePending(int i,int j)
{
    int neighbours = 0;
    int differing;

    //  Goes through each possible direction (up, down, left, right).
    //  Increments neighbours iff there is a neighbour in that direction
    //  (short circuit evaluation).  If there is a neighbour in that direction,
    //  also increments differing iff that neighbour differs from the spin
    //  in position (i,j).
    //  This shamelessly treats true as 1 and false as 0.
    differing = ( (i != 0 && ++neighbours) && (spins[i-1][j] != spins[i][j]) )
        +       ( (j != 0 && ++neighbours) && (spins[i][j-1] != spins[i][j]) )
        +       ( ((i != spins.size()-1) && ++neighbours) && (spins[i+1][j] != spins[i][j]) )
        +       ( ((j != spins[i].size()-1) && ++neighbours) && (spins[i][j+1] != spins[i][j]) );

    // There was an update pending on (i,j) iff differing neighbours were the
    // majority of the neighbours
    return differing > neighbours/2;
}

