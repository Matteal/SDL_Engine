#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

#include "Input.h"

class Window
{
    public:
        Window(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Window();

        void initWindow();
        void mainloop();

    protected:

    private:

        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Event m_events;

        Input m_input;
};

#endif // WINDOW_H
