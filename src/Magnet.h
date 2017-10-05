#ifndef MAGNET_H
#define MAGNET_H

#include <random>
#include <vector>

class Magnet
{
    public:
        Magnet(unsigned width, unsigned height);
        Magnet(std::vector<std::vector<int>> spins);
            // Magnet is initialised randomly or with specific spins
        // Getters
        unsigned getHeight(void);
        unsigned getWidth(void);
        const std::vector<std::vector<int>>& getSpins(void);

        bool randomUpdate(void);
            // Attemps a random update, returning true iff an update occurred.
        bool update(unsigned i, unsigned j);
            // Updates (i,j), if possible.  Returns true iff update occurred.
        bool isStable(void);

    private:
        std::vector<std::vector<int>> spins;
        std::mt19937 rng;   // Mersenne twister random number generator.
        bool updatePending(unsigned i, unsigned j);
            // Whether or not (i,j) is due an update.
};

#endif
