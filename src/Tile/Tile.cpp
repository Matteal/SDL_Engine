#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) : Sprite(renderer, texture, 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT), m_isEmpty(true), m_isBoat(false), m_posX(x), m_posY(y), m_boat(NULL)
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

void Tile::setIsEmpty(bool isEmpty)
{
    m_isEmpty = isEmpty;
}

bool Tile::getIsEmpty()
{
    return m_isEmpty;
}

void Tile::setIsBoat(bool isBoat)
{
    m_isBoat = isBoat;
}

bool Tile::getIsBoat()
{
    return m_isBoat;
}


void Tile::SetTile(void* tile, int orientation)
{
    m_tile[orientation] = tile;
}

void* Tile::getTile(int orientation)
{
    return  m_tile[orientation];
}

int Tile::getPosX()
{
    return m_posX;
}

int Tile::getPosY()
{
    return m_posY;
}
