#ifndef GAME_H
#define GAME_H

#include "Scene.h"


class Game : public Scene
{
    public:
        Game(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~Game();

        void update(Input* input);
        void render();
    protected:

    private:
};

#endif // GAME_H
