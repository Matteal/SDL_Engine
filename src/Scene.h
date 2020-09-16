#ifndef SCENE_H
#define SCENE_H

//#define MAX_SPRITE 100

#include <SDL.h>

#include "Button.h"



class Scene
{
    public:
        Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~Scene();

        void render();

    protected:

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_textureArray[NB_IMAGE];

        Sprite m_jouer;
};

//class MainMenu : Scene
//{
//    public:
//        void setPlayButton();
//};

#endif // SCENE_H
