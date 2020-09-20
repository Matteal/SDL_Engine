#ifndef TILE_H
#define TILE_H

#define TILE_RECT_WIDTH 78
#define TILE_RECT_HEIGHT 40

#define CAMERA_SPEED 0.1

#include "../SDL/Sprite.h"

//0 haut, puis clockwork

class Tile : public Sprite
{
    public:
        Tile(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);
        virtual ~Tile();

        bool estTouche(int curseurx, int curseury);
        bool getIsEmpty();


        // TODO : accesseurs aux pointeurs des tuiles alentours
        void SetTile(void* tile, int orientation);
        void* getTile(int orientation);

        int getPosX();
        int getPosY();

    private:

        void* m_tile[6];

        bool m_isEmpty;
        int m_posX, m_posY;

};

#endif // TILE_H
