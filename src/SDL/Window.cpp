#include "Window.h"

#include <stdlib.h>
#include <SDL_ttf.h>

Window::Window(const char* titleWindow, const int widhtWindow, const int heightWindow, const Uint32 flags) : m_title(titleWindow), m_width(widhtWindow),
                                                                                             m_height(heightWindow), m_flags(flags), m_window(0), m_renderer(0)
{
    test_music0 = NULL;
    test_music1 = NULL;
    test_music2 = NULL;
}

Window::~Window()
{
    //dtor
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    Mix_FreeMusic(test_music0);
    Mix_FreeMusic(test_music1);
    Mix_FreeMusic(test_music2);

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
    int IMGflags = IMG_INIT_JPG | IMG_INIT_PNG ;
    if (! ( IMG_Init(IMGflags) & IMGflags ))
    {
        std::cout << "Error : " << IMG_GetError() << std::endl;
        IMG_Quit();
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError()<<std::endl;
        return false;
    }
    else
    {
        //test_music0 = Mix_LoadMUS("data/music.wav");
        //test_music1 = Mix_LoadMUS("data/main_theme.wav");
        //test_music2 = Mix_LoadMUS("data/battle_theme.wav");
        if(test_music0 == NULL)
        {
            std::cout<<"Erreur"<<std::endl;
        }
    }
    if(TTF_Init() < 0)
    {
        std::cout<<"SDL_ttf could not initialize! SDL_ttf Error: "<< TTF_GetError() <<std::endl;
        return false;
    }
    return true;
}

SDL_Renderer* Window::getRenderer()
{
    return m_renderer;
}

Mix_Music* Window::getMusic(int index)
{
    switch(index)
    {
        case 0:
            return test_music0;
            break;
        case 1:
            return test_music1;
            break;
        case 2:
            return test_music2;
            break;
    }
}
