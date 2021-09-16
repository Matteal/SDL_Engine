#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager(SDL_Renderer* renderer): m_renderer(renderer)
{
    //TODO: charger asynchroniquement les images

    // Buttons
    loadTexture("buttonPlay.png");
    loadTexture("buttonPlayAlt.png");
    loadTexture("buttonQuit.png");
    loadTexture("buttonQuitAlt.png");
    loadTexture("audioOn.png");
    loadTexture("audioOff.png");
    loadTexture("bgMenu.png");

    // Fight Images
    loadTexture("hp.png");
    loadTexture("hpEmpty.png");
    loadTexture("bg.png");
    loadTexture("fightMenu.png");
    loadTexture("fightMenu2.png");
    loadTexture("fightStrike.png");
    loadTexture("fightSurprise.png");
    loadTexture("fightDefend.png");

    // Ships
    loadTexture("cruiser.png");
    loadTexture("cruiserAlt.png");
    loadTexture("armored.png");
    loadTexture("armoredAlt.png");
    loadTexture("raider.png");
    loadTexture("raiderAlt.png");

    // Tiles
    loadTexture("Tiles/tileOutline.png");
    loadTexture("Tiles/tileOutline1.png");
    loadTexture("Tiles/tileOutline2.png");
    loadTexture("Tiles/tile1.png");
    loadTexture("Tiles/tile2.png");
    loadTexture("Tiles/tile3.png");
    loadTexture("Tiles/tile4.png");
    loadTexture("Tiles/tileIsland1.png");

    //how to access:
    //SDL_Texture* sdlt = m_textureMap["buttonPlay"];
}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::operator[](const std::string str)
{
    return m_textureMap[str];
}

void TextureManager::loadTexture(const std::string &path)
{
    SDL_Surface* surface = IMG_Load((DATA_PATH + path).c_str());
    if (surface == NULL)
    {
        std::cout << "An error occured during the surface loading ! " << path <<std::endl;
    }
    else
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);
        SDL_FreeSurface(surface);

        std::string name = path.substr(path.find_last_of('/')+1);
        name = name.substr(0, name.find('.'));

        m_textureMap[name] = texture;
    }
}

