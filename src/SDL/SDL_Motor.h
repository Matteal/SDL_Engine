#ifndef SDL_MOTOR_H
#define SDL_MOTOR_H

#include <iostream>


#include "Window.h"

#include "Sprite.h"

#include "Scene.h"
//#include "../Bridge.h"
#include "../Others/toolbox.h"

#include "TextureManager.h"
#include "SceneManager.h"

class SDL_Motor
{
    public:
        SDL_Motor();
        ~SDL_Motor();

        bool init();
        void mainloop();

        void showPointer(bool answer) const;
        void capturePointer(bool answer) const;
        Window getWindow();

    protected:

    private:
        Window m_window;
        Input m_input;

        Uint32 start;
        Uint32 timer;

        SDL_Renderer* m_renderer;
        TextureManager m_textureManager;
        MusicManager m_musicManager;
        SceneManager* m_sceneManager;
        std::string text;

};


#endif // SDL_MOTOR_H
