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
        Bateau(int posx, int posy);
        ~Bateau();

        int Haut();
        int Bas();
        int Gauche();
        int Droite();
        bool getTour();

        void attack(Bateau &target);


    protected:
        int m_posx;
        int m_posy;

        int m_argent;
        int m_tour;
        int m_armor;


    private:
};


//
//class Player : public Bateau
//{
//    public:
//        Player(int posx, int posy, float vie, float degat, int type, bool tour, int armor);
//        int LevelUp(int m_level);
//        int Depense(int retrait);
//
//    private:
//        int m_level;
//        int m_type;
//};

//class Ennemy : public Bateau
//{
//    public:
//        Ennemy(int posx, int posy, float vie, float degat,int argent, bool tour, int armor);
//};

#endif // BATEAU_H
