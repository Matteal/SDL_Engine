#ifndef WINDOW_H
#define WINDOW_H

#include "Texture.h"
#include <iostream>

#include "Input.h"
#include "Button.h"
#include <SDL_ttf.h>



class Window
{
    public:
        Window(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Window();

        void initWindow();
        void mainloop();
        void AffJeu();
        void Update();
        SDL_Window* getWindow();

    protected:

    private:

        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Event m_events;

        SDL_Texture* m_jouer;
        SDL_Texture* m_quitter;



        Button m_play;
        Button m_quit;

        Input m_input;
};

#endif // WINDOW_H
