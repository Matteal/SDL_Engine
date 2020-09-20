#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#include "../SDL/Scene.h"
#include "../Bridge.h"


class GameFight : public Scene
{
    public:
        GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE], Bridge* bridge);
        ~GameFight();

        void update(Input* input);
        void render();


    protected:
        Bridge* m_bridge;

    private:
};

#endif // GAME_FIGHT_H
