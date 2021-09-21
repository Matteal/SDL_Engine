#include <iostream>
#include "Scene.h"


#include <Windows.h>

Scene::Scene(SDL_Renderer* renderer, MusicManager* musicManager):
    m_renderer(renderer), m_ratioX(1), m_ratioY(1), m_musicManager(musicManager)
{
    //ctr
}

Scene::~Scene()
{
    std::cout << "destroy" << std::endl;
    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
    {
        std::cout << m_tabSprite[i] << std::endl;
        delete(m_tabSprite[i]);
    }
}

void Scene::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,255,255,255);
    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
    {
        m_tabSprite[i]->render();
    }
}

void Scene::changeRatio(float ratioX, float ratioY)
{
    for (auto &sprite : m_tabSprite)
    {
        sprite->actuSDL_Rect(ratioX, ratioY);
    }
    m_ratioX = ratioX;
    m_ratioY = ratioY;
}
