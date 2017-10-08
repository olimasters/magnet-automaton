#ifndef VISUALISER_H
#define VISUALISER_H

#include <SDL2/SDL.h>
#include "Magnet.h"

struct colour
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Visualiser
{
    public:
        Visualiser(const Magnet &magnet, unsigned spinSize, colour positiveColour, colour negativeColour);
        ~Visualiser();
        void updateScreen(void);
    private:
        void writeMagnetToLockedTexture(void *texturePixels);
        void colourSquareInLockedTexture(void *texturePixels, colour pixelColour, unsigned top, unsigned left, unsigned sideLength);
        const Magnet &magnet;
        unsigned spinSize;  // The side length of one spin (px)
        unsigned height;    // Screen height (px)
        unsigned width;     // Screen width (px)
        colour positiveColour;
        colour negativeColour;

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_PixelFormat *pixelFormat;
};

#endif
