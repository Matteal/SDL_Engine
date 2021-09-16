#include "SceneManager.h"

SceneManager::SceneManager(SDL_Renderer* renderer, TextureManager& tm): m_selectedScene(0), m_nextScene(m_selectedScene)
{
    m_tabScene[0] = new MainScene(renderer, tm);
    m_tabScene[1] = new PauseScene(renderer, tm);
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
    // Change the selected Scene at the loop's beggining
    if(m_selectedScene != m_nextScene)
    {
        m_selectedScene = m_nextScene;
    }

    // Call update() of the current Scene
    m_nextScene = m_tabScene[m_selectedScene]->update(input);

}
