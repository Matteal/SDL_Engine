#ifndef TILE_H
#define TILE_H

#define TILE_RECT_WIDTH 78
#define TILE_RECT_HEIGHT 40

#include "../SDL/Sprite.h"

//0 haut, puis clockwork

class Tile : public Sprite
{
    public:
        Tile(SDL_Renderer* renderer, SDL_Texture* texture);
        virtual ~Tile();

        bool estTouche(int curseurx, int curseury);


        // TODO : accesseurs aux pointeurs des tuiles alentours
//        void SetTile(Tile* tile, int orientation);
//
//        Tile* getTile(int orientation);



    private:

        Tile* m_tile[6];

};

#endif // TILE_H
