#ifndef SCENE_H
#define SCENE_H

#define MAX_SPRITE 100

#include <SDL.h>
#include <SDL_mixer.h>

#include <vector>

#include "Sprite.h"
#include "Input.h"
#include "TextureManager.h"
#include "MusicManager.h"

class Scene
{
    public:
        Scene(SDL_Renderer* renderer, MusicManager* musicManager);
        virtual ~Scene();

        virtual void render();
        void changeRatio(float ratioX, float ratioY);
        bool isClick(Input* input);

        virtual int update(Input* input){return -1;};
        SDL_Renderer* m_renderer;

    protected:
        float m_ratioX, m_ratioY;
        MusicManager m_musicMap;

        //SDL_Texture* m_textureArray[NB_IMAGE];
        std::vector<Sprite*> m_tabSprite;

        MusicManager* m_musicManager;
};

#endif // SCENE_H
