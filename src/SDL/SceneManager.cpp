#include "SceneManager.h"

SceneManager::SceneManager(SDL_Renderer* renderer, TextureManager& tm, MusicManager& mm): m_selectedScene(0), m_nextScene(m_selectedScene), m_ratioX(1), m_ratioY(1)
{
    m_tabScene[0] = new MainScene(renderer, tm, mm);
    m_tabScene[1] = new PauseScene(renderer, tm, mm);
}

SceneManager::~SceneManager()
{
    //dtor
}

void SceneManager::changeRatio(SDL_Window* window)
{
    // get real screen size
    int windowHeight;
    int windowWidth;

    SDL_GetWindowSize(window,&windowWidth,&windowHeight);

    // compute ratio window/screen
    float new_ratioX = (float) windowWidth/1920;
    float new_ratioY = (float) windowHeight/1080;

    // change the ratio in the current screen
    m_tabScene[m_selectedScene]->changeRatio(new_ratioX, new_ratioY);

    m_ratioX = new_ratioX;
    m_ratioY = new_ratioY;
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
