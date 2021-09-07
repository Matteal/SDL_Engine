#include "SceneManager.h"

SceneManager::SceneManager(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]): m_selectedScene(0)
{
    m_tabScene[0] = new MainMenu(renderer, textureArray);
    m_tabScene[1] = new PauseMenu(renderer, textureArray);
}

SceneManager::~SceneManager()
{
    //dtor
}

void SceneManager::render()
{
    m_tabScene[m_selectedScene]->render();
}

void SceneManager::update(Input* input)
{
    m_tabScene[m_selectedScene]->update(input);
}
