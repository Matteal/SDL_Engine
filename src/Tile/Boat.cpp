#include "Boat.h"

Boat::Boat(SDL_Renderer* renderer, SDL_Texture* texture, int posx, int posy) : Sprite(renderer, texture, 0, 0, 78, 40)
{
    //ctor
}

Boat::~Boat()
{
    //dstror
}


void Boat::attack(Boat &target)
{
    //init Fight
}

int Boat::getCurrentTileX()
{
    return m_currentTileX;
}

int Boat::getCurrentTileY()
{
    return m_currentTileY;
}

void Boat::setCurrentTileX(int x)
{
    m_currentTileX = x;
}

void Boat::setCurrentTileY(int y)
{
    m_currentTileY = y;
}




// Player
//
//Player::Player(int posx,int posy,float vie,float degat,int type,bool vivant,int argent, int level, bool tour, int armor): Boat(posx,posy,vie,degat,vivant,argent,tour,armor), m_level(level)
//{
//
//}
//
//int Player::Depense(int retrait)
//{
//    if (m_argent > retrait)
//    {
//        m_argent -= retrait;
//        return m_argent;
//    }
//    return m_argent;
//}
//
//
//// Ennemy
//
//Ennemy::Ennemy(int posx,int posy,float vie, float degat,bool vivant,int argent,bool tour,int armor): Boat(posx,posy,vie,degat,vivant,argent,tour,armor)
//{
//
//}
//
