#ifndef WINDOW_H
#define WINDOW_H

#define NB_IMAGE 1

#include <iostream>

#include "Button.h"

#include <SDL_image.h>



class Window
{
    public:
        Window(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Window();

        bool initWindow();

        SDL_Renderer* getRenderer();

    protected:

    private:

        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
//        SDL_Event m_events;
};


#endif // WINDOW_H
