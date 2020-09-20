#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#include "../SDL/Scene.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>



class GameFight : public Scene
{
    public:
        GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~GameFight();

        void update(Input* input);
        void render();
        void Write(TTF_Font* police,const char* file, int charsize, unsigned int r, unsigned int g, unsigned int b,char* text, SDL_Renderer* renderer, int width,int height, int posx, int posy);


    protected:

    private:
        TTF_Font* m_police;
        Mix_Chunk* strike;
        Mix_Chunk* surprise;
        Mix_Chunk* defense;
};

#endif // GAME_FIGHT_H
