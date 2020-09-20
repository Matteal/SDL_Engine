#ifndef BATTLESHIP_H
#define BATTLESHIP_H


class Battleship
{
    public:
        Battleship(int armor, int damage, int life);
        int getArmor();
        int getLife();
        int getDamage();
        void SetArmor (int a);
        void SetLife (int l);
        void SetDamage (int d);
        void AddLife(int p);
        void AddArmor(int p);

    protected:

    private:
        int m_armor;
        int m_damage;
        int m_life;
};

#endif // BATTLESHIP_H
