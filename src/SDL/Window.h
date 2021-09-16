#ifndef WINDOW_H
#define WINDOW_H


#include <iostream>


#include <SDL_image.h>
#include <SDL_mixer.h>


class Window
{
    public:
        Window();
        Window(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Window();

        bool initWindow();

        SDL_Renderer* getRenderer();
        Mix_Music* getMusic(int index);
        SDL_Window* getWindow();
        SDL_Window* m_window;

        Mix_Music* test_music0;
        Mix_Music* test_music1;
        Mix_Music* test_music2;
        bool fullscreen;

    protected:

    private:

        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Renderer* m_renderer;
};


#endif // WINDOW_H
