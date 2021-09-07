#ifndef SCENE_H
#define SCENE_H

#define MAX_SPRITE 100

#include <SDL.h>
#include <SDL_mixer.h>

#include <vector>

#include "Sprite.h"
#include "Input.h"


class Scene
{
    public:
        Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~Scene();

        void render();
        virtual void update(Input* input){};
        SDL_Renderer* m_renderer;

    protected:

        SDL_Texture* m_textureArray[NB_IMAGE];

        std::vector<Sprite*> m_tabSprite;

    private:

};

class MainMenu : public Scene
{
    public:
        MainMenu (SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);

        void update(Input* input);
    private:
        bool m_isAudioOn;
};

class PauseMenu : public Scene
{
    public:
        PauseMenu(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);

        void update(Input* input);
        void render();
};

#endif // SCENE_H
