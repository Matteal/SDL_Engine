#include "SceneManager.h"

SceneManager::SceneManager(SDL_Renderer* renderer, TextureManager& tm): m_selectedScene(0)
{
    m_tabScene[0] = new MainMenu(renderer, tm);
    //m_tabScene[1] = new PauseMenu(renderer, nullptr);
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
