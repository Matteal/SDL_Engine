#ifndef GAME_TILE_H
#define GAME_TILE_H

#include "../SDL/Scene.h"


class GameTile : public Scene
{
    public:
        GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~GameTile();

        void update(Input* input);
        void render();

    protected:

    private:
};

#endif // GAME_H
