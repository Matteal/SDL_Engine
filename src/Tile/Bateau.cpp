#include "Bateau.h"

Bateau::Bateau(int posx,int posy,float vie,float degat,bool vivant,int argent, bool tour, int armor)
{
    //ctor
}

Bateau::~Bateau()
{
    //dstror
}

bool Bateau::Vivant()
{
    if (m_vie > 0)
    {
        m_vivant = false;
        return m_vivant;
    }
    return m_vivant;
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

void Bateau::Dammage(int dammage,int armor)
{
    // ALGO QUI CALCULE LES DEGATS SELON DEGATS (ATT) ET ARMURE (DEF)
    // m_vie -= degats IMPORTANT
}

int Bateau::getDammage()
{
    return m_degat;
}

int Bateau::getArmor()
{
    return m_armor;
}




// Player

Player::Player(int posx,int posy,float vie,float degat,int type,bool vivant,int argent, int level, bool tour, int armor): Bateau(posx,posy,vie,degat,vivant,argent,tour,armor), m_level(level)
{

}

int Player::Depense(int retrait)
{
    if (m_argent > retrait)
    {
        m_argent -= retrait;
        return m_argent;
    }
    return m_argent;
}


// Ennemy

Ennemy::Ennemy(int posx,int posy,float vie, float degat,bool vivant,int argent,bool tour,int armor): Bateau(posx,posy,vie,degat,vivant,argent,tour,armor)
{

}

