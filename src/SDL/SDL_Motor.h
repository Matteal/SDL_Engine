#ifndef SDL_MOTOR_H
#define SDL_MOTOR_H

#include <iostream>


#include "Window.h"
#include "Input.h"
#include "Sprite.h"

#include "Scene.h"
//#include "../Bridge.h"
#include "../Static/toolbox.h"


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
        std::string text;

};

SDL_Texture* chargerTexture(const std::string &chemin, SDL_Renderer* rendu);


#endif // SDL_MOTOR_H
