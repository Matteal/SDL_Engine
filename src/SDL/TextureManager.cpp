#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager(SDL_Renderer* renderer): m_renderer(renderer)
{
    // Buttons
    chargerTexture("buttonPlay.png");
    chargerTexture("buttonPlayAlt.png");
    chargerTexture("buttonQuit.png");
    chargerTexture("buttonQuitAlt.png");
    chargerTexture("audioOn.png");
    chargerTexture("audioOff.png");
    chargerTexture("bgMenu.png");

    // Fight Images
    chargerTexture("hp.png");
    chargerTexture("hpEmpty.png");
    chargerTexture("bg.png");
    chargerTexture("fightMenu.png");
    chargerTexture("fightMenu2.png");
    chargerTexture("fightStrike.png");
    chargerTexture("fightSurprise.png");
    chargerTexture("fightDefend.png");

    // Ships
    chargerTexture("cruiser.png");
    chargerTexture("cruiserAlt.png");
    chargerTexture("armored.png");
    chargerTexture("armoredAlt.png");
    chargerTexture("raider.png");
    chargerTexture("raiderAlt.png");

    // Tiles
    chargerTexture("Tiles/tileOutline.png");
    chargerTexture("Tiles/tileOutline1.png");
    chargerTexture("Tiles/tileOutline2.png");
    chargerTexture("Tiles/tile1.png");
    chargerTexture("Tiles/tile2.png");
    chargerTexture("Tiles/tile3.png");
    chargerTexture("Tiles/tile4.png");
    chargerTexture("Tiles/tileIsland1.png");

    //how to access:
    //SDL_Texture* sdlt = m_textureMap["buttonPlay"];
}

TextureManager::~TextureManager()
{
    //dtor
}

void TextureManager::chargerTexture(const std::string &chemin)
{
    SDL_Surface* surface = IMG_Load((DATA_PATH + chemin).c_str());
    if (surface == NULL)
    {
        std::cout << "Erreur de chargement de surface " << chemin <<std::endl;
    }
    else
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);
        SDL_FreeSurface(surface);

        std::string name = chemin.substr(chemin.find_last_of('/')+1);
        name = name.substr(0, name.find('.'));

        std::cout<<"name : "<<name<<std::endl;
    }
}
