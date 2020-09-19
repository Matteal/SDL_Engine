#ifndef TILE_H
#define TILE_H

#define TILE_RECT_WIDTH 78
#define TILE_RECT_HEIGHT 40

#include "../SDL/Sprite.h"


class Tile : public Sprite
{
    public:
        Tile(SDL_Renderer* renderer, SDL_Texture* texture);
        virtual ~Tile();

        // TODO : accesseurs aux pointeurs des tuiles alentours

    private:

};

#endif // TILE_H
