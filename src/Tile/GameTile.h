#ifndef GAME_TILE_H
#define GAME_TILE_H
#include <iostream>

#define NB_TILE_X 99
#define NB_TILE_Y 100

#define NB_ENNEMIES 1000

#include "../SDL/Scene.h"
#include "Tile.h"
#include "Boat.h"

#include <stdlib.h>


class GameTile : public Scene
{
    public:
        GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~GameTile();

        void updateBoatPos(Boat* boat, int cursorX, int cursorY);
        void update(Input* input);
        void render();

    private:
        Tile* m_map[NB_TILE_X][NB_TILE_Y];
        Sprite m_hover, m_area;

        Player m_player;
        Boat* m_TabBoat[NB_ENNEMIES];

        bool inTravel;
        int boatLastPosX, boatLastPosY;

        int m_OriginCameraX, m_OriginCameraY;
        float m_CameraX, m_CameraY;
        int m_hoverCordX, m_hoverCordY;

        float m_interpolate;


};

#endif // GAME_H
