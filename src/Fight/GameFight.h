#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#include "../SDL/Scene.h"
#include "../Tile/Bateau.h"


class GameFight : public Scene
{
    public:
        GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~GameFight();

        void update(Input* input);
        void render();


    protected:

    private:
};

#endif // GAME_FIGHT_H
