#include "Scene.h"
#include <iostream>

Scene::Scene(const char* titleWindow, const int widhtWindow, const int heightWindow, const Uint32 flags): m_title(titleWindow), m_width(widhtWindow),
                                                                                             m_height(heightWindow), m_flags(flags), m_scene(0), m_renderer(0)
{
    //ctor
}

Scene::~Scene()
{
    SDL_DestroyWindow(m_scene);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

bool Scene::InitScene()
{
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error occurred during SDL initialization : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return false;
    }


    // Création de la fenêtre
    m_scene = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, m_flags);

    if(m_scene == 0)
    {
        std::cout << "Error occurred during window creation phase : " << SDL_GetError() << std::endl;

        return false;
    }


    // Création du renderer
    m_renderer = SDL_CreateRenderer(m_scene, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(m_renderer == NULL)
    {
        m_renderer = SDL_CreateRenderer(m_scene, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

        if(m_renderer == NULL)
        {
            std::cout << "Error occurred during renderer initialization : " << SDL_GetError() << std::endl;

            return false;
        }
    }
    return true;
}

SDL_Renderer* Scene::getRenderer()
{
    return m_renderer;
}
