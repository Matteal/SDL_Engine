#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, SDL_Texture* texture) : Sprite(renderer, texture, 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT), m_isEmpty(true)
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

bool Tile::estTouche(int curseurX,int curseurY)
{
    //collision Sprite
    if(Sprite::estTouche(curseurX, curseurY))
    {
        return true;
//        if(curseurX+20 > curseurY)
//        {
//            return true;
//        }
    }
    return false;
}

bool Tile::getIsEmpty()
{
    return m_isEmpty;
}

void Tile::SetTile(void* tile, int orientation)
{
    m_tile[orientation] = tile;
}

void* Tile::getTile(int orientation)
{
    return  m_tile[orientation];
}
