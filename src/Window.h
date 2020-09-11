#ifndef WINDOW_H
#define WINDOW_H

#define NB_IMAGE 1

//#include "Texture.h"
#include <iostream>

#include "Input.h"
#include "Button.h"

#include <SDL_image.h>



class Window
{
    public:
        Window(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Window();

        void initWindow();
        void mainloop();
        void AffJeu();
        void Update();

    protected:

    private:

        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Event m_events;

        SDL_Texture* m_textureArray[NB_IMAGE];

        Button m_play;
        Button m_quit;

        Input m_input;
};

SDL_Texture* chargerTexture(const std::string &chemin, SDL_Renderer* rendu);

#endif // WINDOW_H
