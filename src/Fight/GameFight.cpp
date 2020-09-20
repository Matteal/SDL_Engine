#include "GameFight.h"

GameFight::GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
{
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[11], 0,0,800,350));

    for(int i=0;i<5;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[9], 50*i,0,50,60));
    }

    for(int i=0;i<5;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[10], 550+50*i,0,50,60));
    }


    for(int i=0;i<3;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[i+14], 10+i*127,360,128,130));
    }
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[12], 0,350,400,150));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[13], 400,350,400,150));

    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[8], 50,100,200,200));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[8], 550,100,200,200));
    m_police = NULL;
    strike = Mix_LoadWAV("data/punch.wav");
    defense = Mix_LoadWAV("data/defense.wav");
    surprise = Mix_LoadWAV("data/surprise.wav");
}

GameFight::~GameFight()
{

}

void GameFight::update(Input* input)
{
    // If Pause Button is Pressed
    if (input->getTouche(SDL_SCANCODE_P))
    {
        input->setSelectedScene(1);
    }
    if (m_tabSprite[11]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
    {
        Mix_PlayChannel(-1,strike,0);
    }
    if (m_tabSprite[12]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
    {
        Mix_PlayChannel(-1,surprise,0);
    }
    if (m_tabSprite[13]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
    {
        Mix_PlayChannel(-1,defense,0);
    }
}

void GameFight::render()
{
    int colorG = (SDL_GetTicks()/10) % 255;
    int colorB = (SDL_GetTicks()/20) % 255;
    SDL_SetRenderDrawColor(m_renderer,0,colorG,colorB,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}

void GameFight::Write(TTF_Font* police,const char* file, int charsize, unsigned int r, unsigned int g, unsigned int b,char* text, SDL_Renderer* renderer, int width,int height, int posx, int posy)
{
    police = TTF_OpenFont(file,charsize);
    SDL_Color color = {r,g,b};
    SDL_Surface* MessageSurface = TTF_RenderText_Blended(police,text,color);
    SDL_Texture* Text = SDL_CreateTextureFromSurface(renù,MessageSurface);
    SDL_Rect rect;
    rect.h = height;
    rect.w = width;
    rect.x = posx;
    rect.y = posy;
    SDL_RenderCopy(renderer,Text,NULL,&rect);
}






