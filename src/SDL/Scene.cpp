#include "Scene.h"
#include <iostream>

Scene::Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]): m_renderer(renderer)
{
    for(int i=0; i<2; i++)
    {
        m_textureArray[i] = textureArray[i];
    }
}

Scene::~Scene()
{
    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
     delete(m_tabSprite[i]);
}


void Scene::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,255,255,255);

    for(unsigned int i = 0; i < m_tabSprite.size(); i++)
        m_tabSprite[i]->render();
}



// ***** MAINMENU ***** //

MainMenu::MainMenu(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
{
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[0], 250,100,300,50)); //Bouton Jouer
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureArray[1], 250,300,300,50)); //Bouton Quitter
}

void MainMenu::update(Input* input)
{
    // If buttonClicked
    if (input->getBoutonSouris(SDL_MOUSEBUTTONDOWN))
    {
        // "Play" Button is pressed
        if(m_tabSprite[0]->estTouche(input->getX(), input->getY(),input->getRoundDOWN(),input->getRoundUP()))
        {
            input->setSelectedScene(2);
        }

        // "Quit" Button is pressed
        else if(m_tabSprite[1]->estTouche(input->getX(), input->getY(),input->getRoundDOWN(),input->getRoundUP()))
        {
            input->setSelectedScene(3);
        }

//         "Quit" Button is pressed
//        else if(m_tabSprite[1]->estTouche(input->getX(), input->getY()))
//        {
//            input->SetTerminer(true);
//        }
    }
}

// ***** PAUSEMENU ***** //

PauseMenu::PauseMenu(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
{

}

void PauseMenu::update(Input* input)
{
    // If Pause Button is Pressed
    if (input->getTouche(SDL_SCANCODE_P))
    {
        input->setSelectedScene(2);
    }

}

void PauseMenu::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
}
