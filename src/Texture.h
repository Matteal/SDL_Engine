#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>


class Texture
{
    public:
        Texture();
        static SDL_Texture* Charger(const std::string &chemin, SDL_Renderer* rendu);

    protected:

    private:


};

#endif // TEXTURE_H
