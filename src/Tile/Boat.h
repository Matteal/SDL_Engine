#ifndef BOAT_H
#define BOAT_H

//#include "SDL.h"
#include "../SDL/Sprite.h"
#include "Tile.h"


class Boat : public Sprite
{
    public:
        Boat(SDL_Renderer* renderer, SDL_Texture* texture, int posx, int posy);
        ~Boat();

        void attack(Boat &target);

        void setCurrentTile(int x, int y);
        void setCurrentTile(Tile* tile);

        Tile* getCurrentTile();

        void render(float interpolation);

    protected:

        Tile* m_currentTile;
        Tile* m_lastTile;

        int m_posRenderX;
        int m_posRenderY;

        int m_argent;
        int m_tour;
        int m_armor;


    private:
};



//class Player : public Bateau
//{
//    public:
//        Player(int posx, int posy);
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
