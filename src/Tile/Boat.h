#ifndef BOAT_H
#define BOAT_H

//#include "SDL.h"
#include "../SDL/Sprite.h"
#include "Tile.h"


class Boat : public Sprite
{
    public:
        Boat(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, int posx, int posy);
        ~Boat();

        void attack(Boat &target);

        void setCurrentTile(Tile* tile);
        Tile* getCurrentTile();

        int getPosX();
        int getPosY();

        void render(float interpolation);

    protected:

        //SDL_Texture* textureR;
        SDL_Texture* m_textureL;

        bool m_toggleTexture;

        Tile* m_currentTile;
        Tile* m_lastTile;

        int m_posRenderX;
        int m_posRenderY;
};

class Player : public Boat
{
    public:
        Player(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, int posx, int posy);

    private:
        int m_level;
        int m_type;
};

//class Ennemy : public Bateau
//{
//    public:
//        Ennemy(int posx, int posy, float vie, float degat,int argent, bool tour, int armor);
//};

#endif // BATEAU_H
