#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "../Tile/Boat.h"

class Battleship
{
    public:
        Battleship();
        Battleship(TYPE_BOAT b, bool player);
        int getArmor();
        double getLife();
        double getEnnemyLife() const;
        int getDamage();
        void SetArmor (int a);
        void SetLife (int l);
        void SetDamage (int d);
        void AddLife(int p);
        void AddArmor(int p);
        void Strike(Battleship& a);
        bool Vivant();
        void stamina();

        void LowerStats();

        void DamageBoost(Battleship b ,int bo);

        void Surprise();

        //Ennmy
        std::string EnnemyActions(Battleship& a);
        void Canon(Battleship& a);
        void Canon_Vache(Battleship& a);
        void Abordage(Battleship& a);


        bool Cost(int state);

    protected:
        int m_armor;
        int m_damage;
        double m_life;
        double m_Ennemylife;
        int m_stamina;

    private:

};

class Ennemy : public Battleship
{
    public:
        Ennemy(TYPE_BOAT b);


    protected:

    private:

};

#endif // BATTLESHIP_H
