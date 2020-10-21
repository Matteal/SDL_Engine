#include "GameFight.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



GameFight::GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE], Bridge* bridge) : Scene(renderer, textureArray), m_bridge(bridge), player(Cruiser,true), ennemy()
{
    //Background
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[11], 0,0,800,350));

    //Player's lives
    for(int i=0;i<5;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[9], 50*i,0,50,60));
    }

    //Enemy's lives
    for(int i=0;i<5;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[9], 550+50*i,0,50,60));
    }

    //Battle sprites
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[26], 50,100,4*78,4*40));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[25], 450,100,4*78,4*40));

    //Battle menu
    for(int i=0;i<3;i++){
        m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[i+14], 10+i*127,360,128,130));
    }
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[12], 0,350,400,150));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[13], 400,350,400,150));
    m_police = NULL;
    strike = Mix_LoadWAV("data/punch.wav");
    defense = Mix_LoadWAV("data/defense.wav");
    surprise = Mix_LoadWAV("data/surprise.wav");
    Turn = true;
    pseudo = toolbox::Pull("data/pseudo.txt");
}

GameFight::~GameFight()
{

}

void GameFight::update(Input* input)
{
     // init combat
    int state;
    if(m_bridge->giveInfoToFight)
    {
       // Updating sprite
        m_tabSprite[11]->setTexture(m_textureArray[m_bridge->playerBoat->getTypeBoat()+26]);
        m_tabSprite[12]->setTexture(m_textureArray[m_bridge->ennemyBoat->getTypeBoat()+25]);
        //delete(m_tabSprite[12]);

//        m_tabSprite[11] = new Sprite(m_renderer, m_textureArray[m_bridge->playerBoat->getTypeBoat()+25], 0,350,400,150);
//        m_tabSprite[12] = new Sprite(m_renderer, m_textureArray[m_bridge->ennemyBoat->getTypeBoat()+26], 400,350,400,150);
        //player = Battleship(m_bridge->playerBoat->getTypeBoat(),true);
        ennemy = Battleship(m_bridge->ennemyBoat->getTypeBoat(),false);
        m_bridge->giveInfoToFight=false;

//        Mix_PlayMusic(test_music2, -1 );
    }


 // If Pause Button is Pressed
    if (input->getTouche(SDL_SCANCODE_P))
    {
        input->setSelectedScene(1);
    }
    if (player.Vivant())
    {
        if (ennemy.Vivant())
        {
            if(Turn)
            {
                if (m_tabSprite[13]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
                {
                    Mix_PlayChannel(-1,strike,0);
                    state = 0;
                    Fight(state);
                }
            if (m_tabSprite[14]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
                {
                    state = 1;
                    Mix_PlayChannel(-1,surprise,0);
                    Fight(state);
                }
            if (m_tabSprite[15]->estTouche(input->getX(),input->getY(),input->getRoundDOWN(),input->getRoundUP()))
                {
                    state = 2;
                    Fight(state);
                    Mix_PlayChannel(-1,defense,0);
                }
            }
            else
            {
                action = ennemy.EnnemyActions(player);
                SDL_Delay(2000);
                Turn = true;
            }
        }
        else
        {
            player.SetLife(player.getLife());
            Turn = true;
            input->setSelectedScene(2);
            m_bridge->giveInfoToTile = true;
        }
    }
    else
    {
        input->setSelectedScene(0);
    }
}

void GameFight::render()
{
    int colorG = (SDL_GetTicks()/10) % 255;
    int colorB = (SDL_GetTicks()/20) % 255;
    SDL_SetRenderDrawColor(m_renderer,0,colorG,colorB,255);
    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
    double object = player.getLife();
    double object2 = ennemy.getLife();
    double object3 = player.getStamina();
    toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,pseudo," Life : ",object,120,80,0,0);
    toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,"Ennemy Life :",object2,120,80,580,0);
    if (Turn)
    {
        toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,pseudo," Turn ",100,80,550,360);
        toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,"Stamina : ",object3,100,80,550,420);
    }
    else
    {
        toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,"Ennemy Turn : ",100,80,450,380);
        toolbox::Write("data/police.ttf",18,m_police,255,255,255,m_renderer,action,90,80,550,380);
    }
}

void GameFight::Fight(int state)
{
        switch(state)
        {
            case 0:
                player.stamina();
                player.Strike(ennemy);
                player.Cost(state);
                Turn = false;
                break;
            case 1:
                player.stamina();
                player.Surprise();
                player.Cost(state);
                Turn = false;
                break;
            case 2:
                player.stamina();
                player.Defend();
                player.Cost(state);
                Turn = false;
                break;
        }
}




