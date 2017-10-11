#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Magnet.h"
#include "Visualiser.h"

struct Settings
{
    // Bundling-together of settings required by the controller.
    unsigned framerate; // Unit: frames per second.
    unsigned spinSize;  // One spin is a spinSize*spinSize (px) square.
    unsigned magnetHeight;    // Unit: spins.
    unsigned magnetWidth;     // Unit: spins.
    colour positiveColour;
    colour negativeColour;
};

class Controller
{
    public:
        Controller(Settings settings);
        void run(void);

    private:
        Settings settings;
        Magnet magnet;
        Visualiser visualiser;
};

#endif
