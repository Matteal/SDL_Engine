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
        void changeRatio(float ratioX, float ratioY);

        virtual int update(Input* input){return -1;};
        SDL_Renderer* m_renderer;

    protected:

        //SDL_Texture* m_textureArray[NB_IMAGE];

        std::vector<Sprite*> m_tabSprite;

    private:

};

class MainMenu : public Scene
{
    public:
    MainMenu (SDL_Renderer* renderer, TextureManager&);

        int update(Input* input);
    private:
        bool m_isAudioOn;
};

class PauseMenu : public Scene
{
    public:
        PauseMenu(SDL_Renderer* renderer, TextureManager& m_textureMap);

        int update(Input* input);
        void render();
};

#endif // SCENE_H
