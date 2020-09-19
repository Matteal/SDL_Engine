#ifndef BATEAU_H
#define BATEAU_H

enum Type
{
    DEFENSE,
    GUERRE,
    SABOTAGE,
};

class Bateau
{
    public:
        Bateau(int posx,int posy,float vie,float degat, bool vivant, int argent, bool tour, int armor);
        ~Bateau();
        bool Vivant();
        int Haut();
        int Bas();
        int Gauche();
        int Droite();
        bool getTour();
        void Dammage (int dammages, int armor);
        void attack(Bateau &target, int dammages);
        int getDammage();
        int getArmor();


    protected:
        int m_posx;
        int m_posy;
        float m_vie;
        float m_degat;
        bool m_vivant;
        int m_argent;
        int m_tour;
        int m_armor;


    private:
};

class Player : public Bateau
{
    public:
        Player(int posx,int posy,float vie,float degat,int type,bool vivant,int argent, int level,bool tour, int armor);
        int LevelUp(int m_level);
        int Depense(int retrait);

    private:
        int m_level;
        int m_type;




};

class Ennemy : public Bateau
{
    public:
        Ennemy(int posx, int posy, float vie, float degat, bool vivant,int argent, bool tour, int armor);
};

#endif // BATEAU_H
