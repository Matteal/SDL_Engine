#include "PauseScene.h"

PauseScene::PauseScene(SDL_Renderer* renderer, TextureManager& m_textureMap) : Scene(renderer)
{

}

int PauseScene::update(Input* input)
{
    // If Pause Button is Pressed
    if (input->getTouche(SDL_SCANCODE_P))
    {
        //input->setSelectedScene(2);
    }
    return 1;
}

void PauseScene::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
}
