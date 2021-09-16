#include "MainScene.h"

MainScene::MainScene(SDL_Renderer* renderer, TextureManager& m_textureMap) : Scene(renderer), m_isAudioOn(true)
{
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["bgMenu"], 0, 0, 1920,1080));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["buttonPlay"], (1920-200)/2,(800-100)/2,200,100, m_textureMap["buttonPlayAlt"])); //Bouton Jouer
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["buttonQuit"], (1920-200)/2,(800+200)/2,200,100, m_textureMap["buttonQuitAlt"])); //Bouton Quitter
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["audioOn"], 10, 10, 100, 100)); //Bouton AudioOn
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["audioOff"], 10, 10, 100, 100)); //Bouton AudioOff

    m_tabSprite[4]->setVisible(false);
}

int MainScene::update(Input* input)
{
//     "Play" Button is pressed
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
    return 0;
}


