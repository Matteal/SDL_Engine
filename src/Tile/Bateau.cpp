#include "Bateau.h"

Bateau::Bateau(int posx, int posy)
{
    //ctor
}

Bateau::~Bateau()
{
    //dstror
}

int Bateau::Haut()
{
    return m_posy;
}

int Bateau::Bas()
{
    return m_posy;
}

int Bateau::Gauche()
{
    return m_posx;
}

int Bateau::Droite()
{
    return m_posx;
}

bool Bateau::getTour()
{
    return m_tour;
}


void Bateau::attack(Bateau &target)
{
    //init Fight
}





// Player
//
//Player::Player(int posx,int posy,float vie,float degat,int type,bool vivant,int argent, int level, bool tour, int armor): Bateau(posx,posy,vie,degat,vivant,argent,tour,armor), m_level(level)
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
//Ennemy::Ennemy(int posx,int posy,float vie, float degat,bool vivant,int argent,bool tour,int armor): Bateau(posx,posy,vie,degat,vivant,argent,tour,armor)
//{
//
//}
//
