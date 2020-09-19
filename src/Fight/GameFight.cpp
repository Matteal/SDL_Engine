#include "GameFight.h"

GameFight::GameFight(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray), b(0,0,3,2,0,true,0,false,1,1), e(0,0,3,2,true,5,false,1)
{
    //ctor
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
}

void GameFight::render()
{
    int colorG = (SDL_GetTicks()/10) % 255;
    int colorB = (SDL_GetTicks()/20) % 255;
    SDL_SetRenderDrawColor(m_renderer,0,colorG,colorB,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}

void GameFight::attack(Bateau attacker, Bateau &target)
{
    //target.Dammage(attacker.getDammage,target.getArmor);
}

void GameFight::fight(bool tour1,bool tour2)
{
    tour1 = true;
    tour2 = false;
    bool finish = false;
    while (!finish)
    {
        if (tour1)
        {
            // A PAUFFINER
            attack(b,&e);
            tour1 = false;
            tour2 = true;
            if (!e.Vivant())
            {
                finish = true;
            }
        }
        else if (tour2)
        {
            attack(e,&b);
            if (!b.Vivant())
            {
                finish = true;
            }
        }
    }
}





