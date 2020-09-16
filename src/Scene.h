#ifndef SCENE_H
#define SCENE_H

#define MAX_SPRITE 100

#include <SDL.h>

#include "Button.h"
#include "Input.h"
#include <vector>



class Scene
{
    public:
        Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~Scene();

        void render();

    protected:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_textureArray[NB_IMAGE];

        std::vector<Sprite*> m_tabSprite;

    private:

};

class MainMenu : public Scene
{
    public:
        MainMenu (SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);

        void update(Input* input);
};

#endif // SCENE_H
