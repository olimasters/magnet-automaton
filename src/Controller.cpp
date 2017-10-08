#include "Controller.h"
#include <chrono>
#include <thread>

Controller::Controller(Settings settings):
    settings(settings),
    magnet(settings.magnetHeight, settings.magnetWidth),
    visualiser(magnet, settings.spinSize, settings.positiveColour, settings.negativeColour)
{
}

void Controller::run(void)
{
    std::chrono::duration<int,std::ratio<1,1000>> framePeriod((int)(1000.0/settings.framerate));
    std::chrono::system_clock::time_point lastFrame;
    for(int i = 0; ; i = (i+1)%1000)
    {
        lastFrame = std::chrono::system_clock::now();
        // Check for magnet stability every 1000 updates.
        if(!i && magnet.isStable())
            break;
        magnet.randomUpdate();
        // We only want to update the screen once 1/framerate has passed.
        std::this_thread::sleep_until(lastFrame + framePeriod);
        visualiser.updateScreen();
    }
}
