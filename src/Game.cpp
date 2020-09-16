#include "Game.h"

Game::Game(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
{
    //ctor
}

Game::~Game()
{

}

void Game::update(Input* input)
{
    // If Pause Button is Pressed
    if (input->getTouche(SDL_SCANCODE_P))
    {
        input->setSelectedScene(2);
    }
}

void Game::render()
{
    int colorG = (SDL_GetTicks()/10) % 255;
    int colorB = (SDL_GetTicks()/20) % 255;
    SDL_SetRenderDrawColor(m_renderer,0,colorG,colorB,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}
