#ifndef GAME_TILE_H
#define GAME_TILE_H
#include <iostream>

#define NB_TILE_X 99
#define NB_TILE_Y 100

#define NB_ENNEMIES 500
#include "../SDL/Scene.h"
#include "Tile.h"
#include "Boat.h"
#include "Bridge.h"

#include <stdlib.h>


class GameTile : public Scene
{
    public:
        GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE], Bridge* bridge);
        ~GameTile();

        Boat* createBoat(TYPE_BOAT type, Tile* startingTile);

        void update(Input* input);
        void render();

    private:

        SDL_Texture* m_textureArray[NB_IMAGE];

        Tile* m_map[NB_TILE_X][NB_TILE_Y];


        Boat* m_player;
        Boat* m_TabBoat[NB_ENNEMIES];

        bool inTravel;
        int boatLastPosX, boatLastPosY;

        float m_CameraX, m_CameraY;
        int m_hoverCordX, m_hoverCordY;

        float m_interpolate;

        Bridge* m_bridge;


};

#endif // GAME_H
