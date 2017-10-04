#ifndef MAGNET_H
#define MAGNET_H

#include <vector>

class Magnet
{
    public:
        Magnet(unsigned width, unsigned height);
            // Magnet is initialised randomly
        // Getters
        unsigned getHeight(void);
        unsigned getWidth(void);
        const std::vector<std::vector<int>>& getSpins(void);

        bool update(unsigned i, unsigned j);
            // Updates (i,j), if possible.  Returns true iff update occurred.
        bool isStable(void);

    private:
        std::vector<std::vector<int>> spins;
        bool updatePending(unsigned i, unsigned j);
            // Whether or not (i,j) is due an update.
};

#endif
