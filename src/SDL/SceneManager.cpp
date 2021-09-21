#include "SceneManager.h"

#include "MainScene.h"
#include "PauseScene.h"
#include "../Game/GameScene.h"
#include "../Game/TaskScene.h"


SceneManager::SceneManager(SDL_Renderer* renderer, TextureManager& tm, MusicManager& mm, SDL_Window* window): m_selectedScene(0), m_nextScene(m_selectedScene), m_window(window), m_ratioX(1), m_ratioY(1)
{
    m_tabScene[0] = new MainScene(renderer, tm, mm);
    m_tabScene[1] = new PauseScene(renderer, tm, mm);
    m_tabScene[2] = new GameScene(renderer, tm, mm);
    m_tabScene[3] = new TaskScene(renderer, tm, mm);
}

SceneManager::~SceneManager()
{
    //dtor
}

void SceneManager::changeRatio()
{
    // get real screen size
    int windowHeight;
    int windowWidth;

    SDL_GetWindowSize(m_window,&windowWidth,&windowHeight);

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
    changeRatio();
    m_tabScene[m_selectedScene]->render();
}

void SceneManager::update(Input* input)
{
    // Change the selected Scene at the loop's beggining
    if(m_selectedScene != m_nextScene)
    {
        if(m_nextScene == 1)
        {
            static_cast<PauseScene*>(m_tabScene[1])->setResumeScene(m_selectedScene);
        }
        m_selectedScene = m_nextScene;
    }

    // Call update() of the current Scene
    m_nextScene = m_tabScene[m_selectedScene]->update(input);

    if(m_nextScene == -1)
    {
        input->SetCloseWindow(true);
    }

}
