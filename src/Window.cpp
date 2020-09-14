#include "Window.h"

#include <stdlib.h>

Window::Window(const char* titleWindow, const int widhtWindow, const int heightWindow, const Uint32 flags) : m_title(titleWindow), m_width(widhtWindow),
                                                                                             m_height(heightWindow), m_flags(flags), m_window(0), m_renderer(0)
{

}

Window::~Window()
{
    //dtor
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

// initialise SDL2
bool Window::initWindow()
{
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error occurred during SDL initialization : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return false;
    }


    // Création de la fenêtre
    m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, m_flags);

    if(m_window == 0)
    {
        std::cout << "Error occurred during window creation phase : " << SDL_GetError() << std::endl;

        return false;
    }


    // Création du renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(m_renderer == NULL)
    {
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

        if(m_renderer == NULL)
        {
            std::cout << "Error occurred during renderer initialization : " << SDL_GetError() << std::endl;

            return false;
        }

        std::cout << "WARNING! RENDERER SOFTWARE ENABLED" << std::endl;
    }
    int IMGflags = IMG_INIT_PNG;
    if (! ( IMG_Init(IMGflags) & IMGflags ))
    {
        std::cout << "Error : " << IMG_GetError() << std::endl;
        IMG_Quit();
        return false;
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError()<<std::endl;
        return false;
    }
    else
    {
        test_music = Mix_LoadWAV("data/music.wav");
        if(test_music == NULL)
        {
            std::cout<<"Erreur"<<std::endl;
        }
    }
    return true;
}

SDL_Renderer* Window::getRenderer()
{
    return m_renderer;
}

Mix_Chunk* Window::getMusic()
{
    return test_music;
}
