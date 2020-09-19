#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, SDL_Texture* texture) : Sprite(renderer, texture, 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT)
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}
