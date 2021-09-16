#include <iostream>
#include "Scene.h"

#include <Windows.h>

Scene::Scene(SDL_Renderer* renderer): m_renderer(renderer)
{
    //ctr
}

Scene::~Scene()
{
    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
     delete(m_tabSprite[i]);
}

void Scene::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,255,255,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}



