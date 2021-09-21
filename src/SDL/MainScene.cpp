#include "MainScene.h"

MainScene::MainScene(SDL_Renderer* renderer, TextureManager& m_textureMap, MusicManager musicMap) : Scene(renderer, &musicMap), m_isAudioOn(true), m_menuTranslation(0.01), m_isClosing(false), m_canInterract(false), m_nextScene(1)
{
    // create all sprites neededm_isClosing
    //m_musicMap.playMusic("main_theme");
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["Plaque_metal"],0,0,1920,1080));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["Apparition_menu_5"],0,0,1920,1080));

    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["Bouton_play_overlay"], 568, 201, 729, 204));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["Bouton_settings_overlay"], 572, 498, 728, 205));
    m_tabSprite.push_back(new Sprite(m_renderer, m_textureMap["Bouton_quit_overlay"], 573, 795, 728, 204));
}

int MainScene::update(Input* input)
{
    if(!m_canInterract) //Si le menu apparait/disparait
    {
        //hide overlay buttons
        m_tabSprite[2]->setVisible(false);
        m_tabSprite[3]->setVisible(false);
        m_tabSprite[4]->setVisible(false);

        if(m_isClosing)//fermeture
        {
            m_menuTranslation -= 0.02;

            if(m_menuTranslation <= 0) //si l'animation est finie
            {
                m_isClosing = false;

                return m_nextScene; //return nextScene
            }
        }else //ouverture
        {
            m_menuTranslation += 0.02;
            if((int)m_menuTranslation == 1) //si l'animation est finie
            {
                m_menuTranslation = 1;
                m_canInterract = true;
            }
        }

        m_tabSprite[1]->setPosition(0, m_menuTranslation*1080 - 1080);

    }else //situation normale
    {
        //show tabs
        m_tabSprite[3]->setVisible(true);
        m_tabSprite[4]->setVisible(true);

        // *** GESTION DES BOUTTONS *** //

        /*
        if(input->getPressedKeys() == SDL_SCANCODE_SPACE)
        {
            std::cout << "HEY HEY" << std::endl;
            return 3;
        }
        */

        // play
        if(m_tabSprite[2]->isTouched(input->getX(), input->getY()))
        {
            m_tabSprite[2]->setVisible(true);
            if(input->getMouseButton(SDL_BUTTON_LEFT) && input->isMouseEvent(SDL_BUTTON_LEFT))
            {
                m_canInterract = false;
                m_isClosing = true;
                m_nextScene = 2;
            }
        }else
        {
            m_tabSprite[2]->setVisible(false);
        }

        // settings
        if(m_tabSprite[3]->isTouched(input->getX(), input->getY()))
        {
            m_tabSprite[3]->setVisible(true);
            if(input->getMouseButton(SDL_BUTTON_LEFT) && input->isMouseEvent(SDL_BUTTON_LEFT))
            {
                m_canInterract = false;
                m_isClosing = true;
                m_nextScene = 1;
            }
        }else
        {
            m_tabSprite[3]->setVisible(false);
        }

        //quit
        if(m_tabSprite[4]->isTouched(input->getX(), input->getY()))
        {
            m_tabSprite[4]->setVisible(true);
            if(input->getMouseButton(SDL_BUTTON_LEFT) && input->isMouseEvent(SDL_BUTTON_LEFT))
            {
                m_canInterract = false;
                m_isClosing = true;
                m_nextScene = -1;
            }
        }else
        {
            m_tabSprite[4]->setVisible(false);
        }
        //m_tabSprite[5]->setVisible(true);
    }

    return 0;
}




