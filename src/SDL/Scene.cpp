#include "Scene.h"
#include <iostream>

#include <Windows.h>
Scene::Scene(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]): m_renderer(renderer)
{
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

MainMenu::MainMenu(SDL_Renderer* renderer, TextureManager& m_textureMap) : Scene(renderer, nullptr), m_isAudioOn(true)

    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["bgMenu"], 0, 0, 800, 500));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["buttonPlay"], 300,100,200,100, m_textureMap["buttonPlayAlt"])); //Bouton Jouer
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["buttonQuit"], 300,300,200,100, m_textureMap["buttonQuitAlt"])); //Bouton Quitter
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["audioOn"], 10, 10, 100, 100)); //Bouton AudioOn
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["audioOff"], 10, 10, 100, 100)); //Bouton AudioOff


    m_tabSprite[4]->setVisible(false);
}

void MainMenu::update(Input* input)
{
    // "Play" Button is pressed
//    if(m_tabSprite[1]->estTouche(input->getX(), input->getY(),input->getRoundDOWN(),input->getRoundUP()))
//    {
//        input->setSelectedScene(2);
//    }
//
//    // "Quit" Button is pressed
//    else if(m_tabSprite[2]->estTouche(input->getX(), input->getY(),input->getRoundDOWN(),input->getRoundUP()))
//    {
//        input->SetTerminer(true);
//    }
//
//    // Toggle Music Button
//    if(m_tabSprite[3]->estTouche(input->getX(), input->getY(), input->getRoundDOWN(), input->getRoundUP()))
//    {
//        if(m_isAudioOn)
//        {
//            Mix_VolumeMusic(0);
//            Mix_Volume(-1,0);
//            m_tabSprite[3]->setVisible(false);
//            m_tabSprite[4]->setVisible();
//            m_isAudioOn = false;
//        }else{
//            Mix_VolumeMusic(30);
//            m_tabSprite[3]->setVisible();
//            m_tabSprite[4]->setVisible(false);
//            m_isAudioOn = true;
//
//        }
//    }
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
        //input->setSelectedScene(2);
    }

}

void PauseMenu::render()
{
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
}
