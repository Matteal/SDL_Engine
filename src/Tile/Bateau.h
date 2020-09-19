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
        Bateau(int posx,int posy,float vie,float degat,int type, bool vivant, int argent, int level);
        ~Bateau();
        bool Vivant();
        int Haut();
        int Bas();
        int Gauche();
        int Droite();
        int Depense(int retrait);


    protected:
        int m_posx;
        int m_posy;
        float m_vie;
        float m_degat;
        int m_type;
        bool m_vivant;
        int m_argent;
        int m_level;


    private:
};

class Player : public Bateau
{
    public:
        int LevelUp(int m_level);



};

class Ennemy : public Bateau
{
    public:

};

#endif // BATEAU_H
