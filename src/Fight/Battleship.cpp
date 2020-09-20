#include "Battleship.h"

Battleship::Battleship(int armor, int damage, int life): m_armor(armor), m_damage(damage), m_life(life)
{
    //ctor
}

int Battleship::getArmor()
{
    return m_armor;
}

int Battleship::getDamage()
{
    return m_damage;
}

int Battleship::getLife()
{
    return m_life;
}

void Battleship::SetArmor(int a)
{
    m_armor = a;
}

void Battleship::AddArmor(int p)
{
    m_armor += p;
}

void Battleship::SetLife(int l)
{
    m_life = l;
}

void Battleship::AddLife(int p)
{
    m_life += p;
}


void Battleship::SetDamage(int d)
{
    m_life = d;
}


