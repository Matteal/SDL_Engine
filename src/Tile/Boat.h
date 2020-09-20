#ifndef BOAT_H
#define BOAT_H

//#include "SDL.h"
#include "../SDL/Sprite.h"
#include "Tile.h"

enum TYPE_BOAT{Cruiser=0, Armored=1, Raider=2}; // Attack, defence, sneaky

TYPE_BOAT findType(int type);

class Boat : public Sprite
{
    public:
        Boat(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, TYPE_BOAT type);
        ~Boat();

        void attack(Boat &target);

        void setCurrentTile(Tile* tile);
        Tile* getCurrentTile();

        TYPE_BOAT getTypeBoat();

        void render(float interpolation);

    protected:

        SDL_Texture* m_textureL;

        bool m_toggleTexture;

        Tile* m_currentTile;
        Tile* m_lastTile;

        int m_posRenderX;
        int m_posRenderY;

        TYPE_BOAT m_typeBoat;
};

//class Player : public Boat
//{
//    public:
//        Player(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, TYPE_BOAT type);
//        Player(Boat* boat);
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
