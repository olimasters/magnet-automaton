#include <iostream>
#include "Magnet.h"

Magnet::Magnet(unsigned height, unsigned width):
    rng(std::random_device{}())
{
    std::uniform_int_distribution<> distribution(0,1);    //Evenly 0s and 1s

    spins.reserve(height);
    for(unsigned i = 0; i < height; i++)
    {
        spins.push_back(std::vector<int>());    //Puts an empty vector on it
        spins[i].reserve(width);
        for(unsigned j = 0; j < width; j++)
            spins[i].push_back(distribution(rng) ? 1 : -1);
    }
}

Magnet::Magnet(std::vector<std::vector<int>> spins):
    rng(std::random_device{}())
{
    this->spins = spins;
}

unsigned Magnet::getHeight(void) const
{
    return spins.size();
}

unsigned Magnet::getWidth(void) const
{
    return spins[0].size();
}

const std::vector<std::vector<int>>& Magnet::getSpins(void) const
{
    return spins;
};

bool Magnet::randomUpdate(void)
{
    std::uniform_int_distribution<> width_distribution(0, getWidth() - 1);
    std::uniform_int_distribution<> height_distribution(0, getHeight() - 1);
    return update(height_distribution(rng), width_distribution(rng));
}

bool Magnet::update(unsigned i, unsigned j)
{
    if(updatePending(i,j))
    {
        spins[i][j] = -spins[i][j];
        return true;
    }
    else
        return false;
}

bool Magnet::isStable(void) const
{
    for(unsigned i = 0; i < spins.size(); i++)
        for(unsigned j = 0; j < (spins[i]).size(); j++)
            if(updatePending(i,j))
                return false;
    //If we reach here then there are no updates pending
    return true;
}

bool Magnet::updatePending(unsigned i, unsigned j) const
{
    unsigned neighbours = 0;
    unsigned differing = 0;

    //  Goes through each possible direction (up, down, left, right).
    //  Increments neighbours iff there is a neighbour in that direction
    //  (short circuit evaluation).  If there is a neighbour in that direction,
    //  also increments differing iff that neighbour differs from the spin
    //  in position (i,j).
    //  This shamelessly treats true as 1 and false as 0.
    differing += ((i != 0 && ++neighbours) && (spins[i-1][j] != spins[i][j]));
    differing += ((j != 0 && ++neighbours) && (spins[i][j-1] != spins[i][j]));
    differing += (((i != spins.size()-1) && ++neighbours) && (spins[i+1][j] != spins[i][j]));
    differing += (((j != spins[i].size()-1) && ++neighbours) && (spins[i][j+1] != spins[i][j]));

    // There was an update pending on (i,j) iff differing neighbours were the
    // majority of the neighbours
    return differing > neighbours/2;
}

