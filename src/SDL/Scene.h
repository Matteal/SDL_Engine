#ifndef SCENE_H
#define SCENE_H

#define MAX_SPRITE 100

#include <SDL.h>
#include <SDL_mixer.h>

#include <vector>

#include "Sprite.h"
#include "Input.h"
#include "TextureManager.h"

class Scene
{
    public:
        Scene(SDL_Renderer* renderer);
        ~Scene();

        void render();
        virtual int update(Input* input){};
        SDL_Renderer* m_renderer;

    protected:

        //SDL_Texture* m_textureArray[NB_IMAGE];
        std::vector<Sprite*> m_tabSprite;
};

#endif // SCENE_H
