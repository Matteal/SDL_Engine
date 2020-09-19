#ifndef GAME_TILE_H
#define GAME_TILE_H
#include <iostream>

#define NB_TILE_X 100
#define NB_TILE_Y 100

#include "../SDL/Scene.h"
#include "Tile.h"

#include <stdlib.h>


class GameTile : public Scene
{
    public:
        GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~GameTile();

        void update(Input* input);
        void render();

    private:
        Tile* m_map[NB_TILE_X][NB_TILE_Y];
       Sprite m_hover;

       int m_hoverCordX, m_hoverCordY;
};

#endif // GAME_H
