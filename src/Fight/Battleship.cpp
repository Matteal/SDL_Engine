#include "Battleship.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

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
                m_stamina = 10;
                m_LIFEMAX = m_life;
                break;
            case 1:
                m_armor = rand()%3+2;
                m_life = rand()%10+30;
                m_damage = rand()%1+1;
                m_stamina = 10;
                m_LIFEMAX = m_life;
                break;
            case 2:
                m_armor = rand()%2+1;
                m_life = rand()%15+20;
                m_damage = rand()%2+1;
                m_stamina = 10;
                m_LIFEMAX = m_life;
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
    m_compteur = 0;
    m_Normalize = false;
}

// Getter

int Battleship::getArmor()
{
    return m_armor;
}

int Battleship::getDamage()
{
    return m_damage;
}

int Battleship::getStamina()
{
    return m_stamina;
}

double Battleship::getLife()
{
    return m_life;
}

// Setter

void Battleship::SetArmor(int a)
{
    m_armor = a;
}

void Battleship::SetLife(int l)
{
    m_life = l;
}

void Battleship::SetDamage(int d)
{
    m_life = d;
}

// Player

void Battleship::Heal(int p)
{
    if (p == 1)
    {
        if(m_LIFEMAX-m_life > m_LIFEMAX*.6)
        {
            if (m_LIFEMAX%2 == 0)
            {
                m_life+=m_LIFEMAX/4;
                std::cout <<"Even > 0.6 "<<std::endl;
            }
            else
            {
                m_LIFEMAX++;
                m_life+=m_LIFEMAX/4;
                std::cout <<"Odd > 0.6 "<<std::endl;
            }
        }
        else
        {
            if (m_LIFEMAX%2 == 0)
            {
                m_life+=m_LIFEMAX/8;
                std::cout <<"Even < 0.6" << std::endl;
            }
            else
            {
                m_LIFEMAX++;
                m_life+=m_LIFEMAX/8;
                std::cout <<"Odd < 0.6" << std::endl;
            }
        }
    }
    else
    {
        if(m_LIFEMAX-m_life < m_LIFEMAX*.4)
        {
            if (m_LIFEMAX%2 == 0)
            {
                m_life-=m_LIFEMAX/4;
                std::cout <<"Even < 0.4 "<<std::endl;
            }
            else
            {
                m_LIFEMAX++;
                m_life-=m_LIFEMAX/4;
                std::cout <<"Odd < 0.4 "<<std::endl;
            }
        }
        else
            {
            if (m_LIFEMAX%2 == 0)
            {
                m_life-=m_LIFEMAX/8;
                std::cout <<"Even > 0.4" << std::endl;
            }
            else
            {
                m_LIFEMAX++;
                m_life-=m_LIFEMAX/8;
                std::cout <<"Odd > 0.4" << std::endl;
            }
        }
    }
}

void Battleship::stamina()
{
    m_stamina += 1;
}

void Battleship::Strike(Battleship& a)
{
    double tmp = (m_damage*(1-m_armor/5));
    a.m_life -= round(tmp);
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

void Battleship::DamageBoost(int bo)
{
    m_damage+=bo;
}

void Battleship::Defend()
{
    double tmp = round(m_armor+m_damage/5);
    m_armor *= tmp;
    std::cout << "Armure = " <<m_armor << std::endl;
}

void Battleship::Surprise()
{
    srand(time(NULL));
    int action = rand()%2;
    if(action == 1)
    {
        int chaos = rand()%2;
        if (chaos == 1)
        {
            switch(m_damage)
            {
                case 0:
                        DamageBoost(2);
                        std::cout << "Damage = " << m_damage << std::endl;
                case 1:
                        break;
                case 2:
                        DamageBoost(-1);
                        std::cout <<"Damage -1"<<std::endl;
                        std::cout << "Damage = " << m_damage << std::endl;
                        break;
                default:
                        DamageBoost(-2);
                        std::cout <<"Damage -2"<<std::endl;
                        std::cout << "Damage = " << m_damage << std::endl;
                        break;
            }
        }
        else
        {
            DamageBoost(2);
            std::cout << "Damage +2" <<std::endl;
            std::cout << "Damage = " << m_damage << std::endl;
        }

    }
    else
    {
        int chaos = rand()%2;
        if(chaos == 1)
        {
            std::cout << "Heal+ : " << m_life <<std::endl;
            Heal(chaos);
        }
        else
        {
            std::cout << "Heal- : " << m_life << std::endl;
            Heal(chaos);
        }
    }
}

void Battleship::LowerStats(bool normalize)
{
    if (normalize)
    {
        std::cout << "Before LS : Armor = " << m_armor << "Life = " << m_life << "Damage = " << m_damage << std::endl;
        m_armor = round(m_armor*1.15);
        m_life = round(m_life*1.15);
        m_damage = round(m_damage*1.15);
        std::cout << "After LS : Armor = " << m_armor << "Life = " << m_life << "Damage = " << m_damage << std::endl;
    }
    else
    {
        std::cout << "Before LS : Armor = " << m_armor << "Life = " << m_life << "Damage = " << m_damage << std::endl;
        m_armor = round(m_armor*0.85);
        m_life = round(m_life*0.85);
        m_damage = round(m_damage*0.85);
        std::cout << "After LS : Armor = " << m_armor << "Life = " << m_life << "Damage = " << m_damage << std::endl;
    }

}

//Ennemy

void Battleship::Canon(Battleship &a)
{
    Strike(a);
}

void Battleship::Canon_Vache(Battleship &a)
{

}

void Battleship::Abordage(Battleship &a)
{
    //a.LowerStats();
}

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


void Battleship::Cost(int state)
{
    if (m_stamina > 2)
    {
        switch (state)
            {
                case 0:
                    m_compteur ++;
                    m_stamina -= 3;
                    break;
                case 1:
                    m_compteur ++;
                    m_stamina -= 2;
                    break;
                case 2:
                    m_compteur ++;
                    m_stamina += 1;
                    break;
            }
    }
    else
    {
        switch (state)
            {
                case 0:
                    m_compteur ++;
                    break;
                case 1:
                    m_compteur ++;
                    break;
                case 2:
                    m_compteur ++;
                    break;
            }
    }
    if(!m_Normalize && m_stamina < 2)
    {
        tmp = m_compteur;
        LowerStats(false);
        std::cout << "Not Normalize" << std::endl;
        m_Normalize = true;
    }
    if(m_Normalize)
    {
        std::cout << "tmp = " << tmp << std::endl;
        std::cout << "compteur :" << m_compteur << std::endl;
        if(m_compteur == tmp+3)
        {
            std::cout << "NORMALIZE" << std::endl;
            LowerStats(true);
            m_Normalize = false;
        }
    }
}



