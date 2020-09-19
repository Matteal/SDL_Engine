#include "Bateau.h"

Bateau::Bateau(int posx,int posy,float vie,float degat,int type,bool vivant,int argent, int level)
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

int Bateau::Depense(int retrait)
{
    if (m_argent > retrait)
    {
        m_argent -= retrait;
        return m_argent;
    }
    return m_argent;
}
