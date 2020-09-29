#include "Battleship.h"
#include "stdlib.h"
#include "time.h"

Battleship::Battleship()
{
    //cstr
}
Battleship::Battleship(TYPE_BOAT b, bool player)
{
    srand(time(NULL));
    if (player)
    {
        switch(b)
        {
            case 0:
                m_armor = rand()%1+1;
                m_life = rand()%10+20;
                m_damage = rand()%3+3;
                break;
            case 1:
                m_armor = rand()%3+2;
                m_life = rand()%10+30;
                m_damage = rand()%1+1;
                break;
            case 2:
                m_armor = rand()%2+1;
                m_life = rand()%15+20;
                m_damage = rand()%2+1;
                break;
        }
    }
    else
    {
        switch(b)
        {
            case 0:
                m_armor = rand()%2+2;
                m_life = rand()%3+10;
                m_damage = rand()%4+2;
                break;
            case 1:
                m_armor = rand()%4+2;
                m_life = rand()%3+10;
                m_damage = rand()%2+2;
                break;
            case 2:
                m_armor = rand()%1+2;
                m_life = rand()%3+10;
                m_damage = rand()%1+2;
                break;
        }
    }
}

int Battleship::getArmor()
{
    return m_armor;
}

int Battleship::getDamage()
{
    return m_damage;
}

double Battleship::getEnnemyLife() const
{
    return m_Ennemylife;
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

void Battleship::Strike(Battleship& a)
{
    a.m_life -= m_damage;
}

bool Battleship::Vivant()
{
    if (m_life <= 0)
    {
        m_life = 0;
        return false;
    }
    return true;
}

double Battleship::getLife()
{
    return m_life;
}

void Battleship::Canon(Battleship &a)
{
    Strike(a);
}

void Battleship::Canon_Vache(Battleship &a)
{

}

void Battleship::Abordage(Battleship &a)
{

}

/*void Battleship::DamageBoost(Battleship b,int bo)
{
    //this.AddLife(-(b.getDamage()-this.getArmor()) + bo);
}

void Battleship::Surprise()
{
    srand(time(NULL));
    int action = rand()%1;
    if(action)
    {
        int chaos = rand()%1;
        if(chaos)
        {
            //this.DamageBoost(-2);
        }
        else
        {
            //this.DamageBoost(2);
        }
    }
    else
    {
        int chaos = rand()%1;
        if(chaos)
        {
            this.Heal(-1);
        }
        else
        {
            this.Heal(2);
        }
    }
}*/

std::string Battleship::EnnemyActions(Battleship &a)
{
    srand(time(NULL));
    //const std::string &attack = "";
    int alea = rand()%99+1;
    if ((alea >= 1) && (alea<= 55))
    {
        Canon(a);
        const std::string &attack1 = "Canon";
        return attack1;
    }
    else if ((alea >= 56) && (alea <= 90))
    {
        Canon_Vache(a);
        const std::string &attack2 = "Canon a vache";
        return attack2;
    }
    else
    {
        Abordage(a);
        const std::string &attack3 = "Abordage";
        return attack3;
    }
}



void Battleship::stamina()
{
    m_stamina += 1;
}

void Battleship::LowerStats()
{
    srand(time(NULL));
}

bool Battleship::Cost(int state)
{
    if (m_stamina > 2)
    {
        switch (state)
        {
        case 0:
            m_stamina -= 3;
            return true;
        case 1:
            m_stamina -= 2;
            return true;
        case 2:
            m_stamina += 1;
            return true;
        }
    }
    else
    {
        LowerStats();
        return false;
    }
    return true;
}



