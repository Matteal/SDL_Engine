#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "../Tile/Boat.h"

class Battleship
{
    public:
        Battleship();
        Battleship(TYPE_BOAT b, bool player);

        // getteur

        int getArmor();
        double getLife();
        int getDamage();
        int getStamina();

        //setteur

        void SetArmor (int a);
        void SetLife (int l);
        void SetDamage (int d);

        // player

        void DamageBoost(int bo);
        void Heal(int p);
        void Defend();
        void Strike(Battleship& a);
        bool Vivant();
        void stamina();
        void LowerStats(bool normalize);
        void DamageBoost(Battleship b ,int bo);
        void Surprise();

        //Ennmy

        std::string EnnemyActions(Battleship& a);
        void Canon(Battleship& a);
        void Canon_Vache(Battleship& a);
        void Abordage(Battleship& a);
        void Cost(int state);

    protected:
        int m_armor;
        int m_damage;
        int m_life;
        int m_stamina;
        int m_LIFEMAX;
        bool m_Normalize;
        int m_compteur;
        int tmp;


    private:

};

#endif // BATTLESHIP_H
