#include "Boat.h"


TYPE_BOAT findType(int type)
{
    switch(type)
    {
    case 0:
        return Cruiser;
        break;
    case 1:
        return Armored;
        break;
    case 2:
        return Raider;
        break;
    default:
        std::cout<<"Error : TypeBoat index "<<type<<" doesn't exist"<<std::endl;
        break;
    }
}


Boat::Boat(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, TYPE_BOAT type) : Sprite(renderer, textureR, 0, 0, 78, 40), m_textureL(textureL), m_toggleTexture(true), m_currentTile(NULL), m_lastTile(NULL), m_typeBoat(type)

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

void Boat::setCurrentTile(Tile* tile)
{

        if(m_currentTile != NULL)
        {
            m_currentTile->setIsEmpty(true);
            m_currentTile->setIsBoat(false);
        }


        if(tile != NULL)
        {
            tile->setIsEmpty(false);
            tile->setIsBoat(true);
        }


        m_lastTile = m_currentTile;
        m_currentTile = tile;
}

Tile* Boat::getCurrentTile()
{
    return m_currentTile;
}


TYPE_BOAT Boat::getTypeBoat()
{
    return m_typeBoat;
}

void Boat::render(float interpolation)
{
    SDL_Rect* rectLast = m_lastTile->getSDL_Rect();
    SDL_Rect* rectCurrent = m_currentTile->getSDL_Rect();
    setPosition((1-interpolation)*rectLast->x + interpolation*rectCurrent->x, (1-interpolation)*rectLast->y + interpolation*rectCurrent->y -8);
    //Sprite::render();
    if(rectLast->x < rectCurrent->x)
        m_toggleTexture = false;
    else if(rectLast->x > rectCurrent->x)
        m_toggleTexture = true;

    if(m_toggleTexture)
    {
        SDL_RenderCopy(m_renderer,m_texture,NULL,&m_rect);
    }else
    {
        SDL_RenderCopy(m_renderer,m_textureL,NULL,&m_rect);
    }

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
