#include "Texture.h"

Texture::Texture()
{
    //ctor
}

SDL_Texture* Texture::Charger(const std::string &chemin, SDL_Renderer* rendu)
{
    SDL_Surface* surface = IMG_Load(chemin.c_str());
    SDL_Texture* texture;
    if (surface == NULL)
    {
        std::cout << "Erreur de chargement de surface " <<std::endl;
        texture = NULL;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(rendu,surface);
        SDL_FreeSurface(surface);
    }
    return texture;
}


