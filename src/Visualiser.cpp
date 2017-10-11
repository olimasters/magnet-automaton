#include "Visualiser.h"

Visualiser::~Visualiser()
{
    SDL_FreeFormat(pixelFormat);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Visualiser::Visualiser(const Magnet &magnet, unsigned spinSize, colour positiveColour, colour negativeColour):
    magnet(magnet),
    spinSize(spinSize),
    height(magnet.getHeight()*spinSize),
    width(magnet.getWidth()*spinSize),
    positiveColour(positiveColour),
    negativeColour(negativeColour)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Magnet Automaton", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, width, height);

    pixelFormat = SDL_AllocFormat(SDL_GetWindowPixelFormat(window));
}

void Visualiser::updateScreen(void)
{
    int pitch;
    void *texturePixels;
    SDL_LockTexture(texture, NULL, &texturePixels, &pitch);
    writeMagnetToLockedTexture(texturePixels);
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void Visualiser::writeMagnetToLockedTexture(void *texturePixels)
{
    std::vector<std::vector<int>> currentSpins = magnet.getSpins();
    colour pixelColour;
    // We iterate through the current spins and colour a square for each one.
    for(unsigned i = 0; i < magnet.getHeight(); i++)
        for(unsigned j = 0; j < magnet.getWidth(); j++)
        {
            pixelColour = currentSpins[i][j] == 1 ? positiveColour : negativeColour;
            colourSquareInLockedTexture(texturePixels, pixelColour, i*spinSize, j*spinSize, spinSize);
        }
}

void Visualiser::colourSquareInLockedTexture(void *texturePixels, colour pixelColour, unsigned top, unsigned left, unsigned sideLength)
{
    // Colours in the square with corner co-ordinates (top,left) and side length sideLength with colour pixelColour.
    for(unsigned i = top; i < top+sideLength; i++)
        for(unsigned j = left; j < left+sideLength; j++)
            ((Uint32*)texturePixels)[i*width + j] = SDL_MapRGB(pixelFormat, pixelColour.r, pixelColour.g, pixelColour.b);
}
