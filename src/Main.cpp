#include <iostream>
#include "Controller.h"

int main(int argc, char *argv[])
{
    Settings settings;
    settings.framerate = 1000;
    settings.magnetHeight = 20;
    settings.magnetWidth = 20;
    settings.spinSize = 20;
    settings.positiveColour = {255,0,0};
    settings.negativeColour = {0,0,255};
    Controller controller(settings);
    controller.run();
    std::cout << "Stability achieved." << std::endl;
    return 0;
}
