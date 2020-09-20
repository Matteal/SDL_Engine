#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#include "../SDL/Scene.h"
#include "../Bridge.h"

#include <SDL_ttf.h>
#include <SDL_mixer.h>


class GameFight : public Scene
{
    public:
        GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE], Bridge* bridge);
        ~GameFight();

        void update(Input* input);
        void render();
        void Write(const char* file, int charsize);

        Bridge* m_bridge;

    protected:

    private:
        TTF_Font* police;
        Mix_Chunk* strike;
        Mix_Chunk* surprise;
        Mix_Chunk* defense;
};

#endif // GAME_FIGHT_H
