#include "GameTile.h"

GameTile::GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
{
    //ctor
}

GameTile::~GameTile()
{

}

void GameTile::update(Input* input)
{

}

void GameTile::render()
{
    int colorG = (SDL_GetTicks()/10) % 255;
    int colorB = (SDL_GetTicks()/20) % 255;
    SDL_SetRenderDrawColor(m_renderer,0,colorG,colorB,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}
