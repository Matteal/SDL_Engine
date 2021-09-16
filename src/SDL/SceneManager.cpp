#include "SceneManager.h"

SceneManager::SceneManager(SDL_Renderer* renderer, TextureManager& tm): m_selectedScene(0), m_nextScene(m_selectedScene),  m_ratioX(1), m_ratioY(1)
{
    m_tabScene[0] = new MainScene(renderer, tm);
    m_tabScene[1] = new PauseScene(renderer, tm);
}

SceneManager::~SceneManager()
{
    //dtor
}

void SceneManager::changeRatio(SDL_Window* window)
{
    int windowHeight;
    int windowWidth;

    SDL_GetWindowSize(window,&windowWidth,&windowHeight);

    float new_ratioX = (float) windowWidth/1920;
    float new_ratioY = (float) windowHeight/1080;

    //std::cout << new_ratioX << ':' << new_ratioY << std::endl;
    m_tabScene[m_selectedScene]->changeRatio(new_ratioX, new_ratioY);

    m_ratioX = new_ratioX;
    m_ratioY = new_ratioY;
   //m_textureM->changeRatio((1-m_ratioX)+new_ratioX, (1-m_ratioY)+new_ratioY);
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
