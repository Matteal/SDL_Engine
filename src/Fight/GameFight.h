#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#include "../SDL/Scene.h"
#include "../Tile/Bridge.h"
#include "Battleship.h"
#include "../Static/toolbox.h"
#include <SDL_mixer.h>
#include <string>



class GameFight : public Scene
{
    public:
        GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE], Bridge* bridge);
        ~GameFight();

        void update(Input* input);
        void render();

        void Fight(int state);
        //void Write(char* file, int charsize, TTF_Font* font, unsigned int r, unsigned int g, unsigned int b, SDL_Renderer* renderer, const std::string &text,int object, int width, int height, int posx, int posy);




    protected:

    private:
        Bridge* m_bridge;
        TTF_Font* m_police;
        Mix_Chunk* strike;
        Mix_Chunk* surprise;
        Mix_Chunk* defense;

        Battleship player;
        Battleship ennemy;

        bool Turn;
        std::string action;
        std::string pseudo;
};

#endif // GAME_FIGHT_H
