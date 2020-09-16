#include "Scene.h"
#include <iostream>

Scene::Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]): m_renderer(renderer), m_jouer(m_renderer, textureArray[0], 250,100,300,50)
{
    for(int i=0; i<2; i++)
    {
        m_textureArray[i] = textureArray[i];
    }


}

Scene::~Scene()
{

}

void Scene::render()
{
    m_jouer.render();
}
