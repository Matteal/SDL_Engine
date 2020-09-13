#ifndef SDL_MOTOR_H
#define SDL_MOTOR_H

#include <iostream>

#define NB_IMAGE 1
#include <SDL_image.h>

#include "Window.h"
#include "Input.h"
#include "Button.h"


class SDL_Motor
{
    public:
        SDL_Motor();
        ~SDL_Motor();

        bool init();
        void mainloop();

    protected:

    private:
        Window m_window;
        Input m_input;

        SDL_Texture* m_textureArray[NB_IMAGE];
        SDL_Renderer* m_renderer;

        Button m_play;
        Button m_quit;
};

SDL_Texture* chargerTexture(const std::string &chemin, SDL_Renderer* rendu);


#endif // SDL_MOTOR_H
