#include "PauseScene.h"

PauseScene::PauseScene(SDL_Renderer* renderer, TextureManager& m_textureMap, MusicManager musicMap) : Scene(renderer, &musicMap), m_offsetScaling(75), m_cursorMusic(3), m_cursorSFX(3), m_menuTranslation(0.01), m_isClosing(false), m_animationOnMenu(true), m_nextScene(-1)
{
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["Plaque_metal"],0,0,1920,1080));

    //Volume Music
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["chains"],0, 0, 1920, 1080));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["Bouton_Music"],568, 151, 729, 204));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["scaling_cursor"],727,240,30,30));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["menu_button_left"],578,180,150,150));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["menu_button_right"],1137,180,150,150));

    //Volume SFX
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["Bouton_SFX"],568, 421, 729, 204));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["scaling_cursor"],727,510,30,30));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["menu_button_left"],578,450,150,150));
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["menu_button_right"],1137,450,150,150));

    //Resume
    m_tabSprite.push_back(new Sprite(m_renderer,m_textureMap["Bouton_Resume"],568, 751, 729, 204));

    //chains

    //prepare offset
    int x,y;
    for(int i=0; i<10; i++)
    {
        m_tabSprite[i+1]->getPosition(x, y);
        m_recordPos[i] = y;
        m_tabSprite[i+1]->setPosition(x, y - 1080);
    }
}

int PauseScene::update(Input* input)
{
    if(m_animationOnMenu) //Si le menu apparait/disparait
    {

        if(m_isClosing)//fermeture
        {
            m_menuTranslation -= 0.02;

            if(m_menuTranslation <= 0) //si l'animation est finie
            {
                m_isClosing = false;

                return m_nextScene;
            }
        }else //ouverture
        {
            m_menuTranslation += 0.02;
            //std::cout << m_menuTranslation << std::endl;
            if((int)m_menuTranslation == 1) //si l'animation est finie
            {
                m_menuTranslation = 1;
                m_animationOnMenu = false;
            }
        }

        int x,y;
        m_tabSprite[8]->getPosition(x, y);

        for(int i=0; i<10; i++)
        {
            m_tabSprite[i+1]->getPosition(x, y);
            m_tabSprite[i+1]->setPosition(x, (m_recordPos[i] - 1080)*(1-m_menuTranslation) + (m_recordPos[i])*(m_menuTranslation) );

        }
    }else //situation normale
    {

        if(m_tabSprite[10]->isTouched(input->getX(), input->getY()))
        {
            if(input->getMouseButton(SDL_BUTTON_LEFT) && input->isMouseEvent(SDL_BUTTON_LEFT))
            {
                m_animationOnMenu = true;
                m_isClosing = true;
            }
        }
    }

    actuSoundSettings(input);

    return 1;
}

void PauseScene::actuSoundSettings(Input* input)
{
        // *** MUSIC MISK *** //
    if(m_tabSprite[4]->isClicked(input)) //Lower music
    {
        if(m_cursorMusic != 0)
        {
            m_cursorMusic --;
        }
    }

    if(m_tabSprite[5]->isClicked(input)) //Upper Music
    {
        if(m_cursorMusic != 5)
        {
            m_cursorMusic ++;
        }
    }
    //actu cursorMusic
    int x,y;
    m_tabSprite[3]->getPosition(x, y);
    m_tabSprite[3]->setPosition(727+(m_offsetScaling*m_cursorMusic),y );
    m_musicManager->setMusicVolume(25*m_cursorMusic);

    // *** SFX MISK *** //
    if(m_tabSprite[8]->isClicked(input)) //Lower SFX
    {
        if(m_cursorSFX != 0)
        {
            m_cursorSFX --;
        }
    }

    if(m_tabSprite[9]->isClicked(input)) //Upper SFX
    {
        if(m_cursorSFX != 5)
        {
            m_cursorSFX ++;
        }
    }

    //actu CursorSFX
    m_tabSprite[7]->getPosition(x, y);
    m_tabSprite[7]->setPosition(727+(m_offsetScaling*m_cursorSFX),y );
    m_musicManager->setSfxVolume(25*m_cursorSFX);
}

void PauseScene::setResumeScene(int sceneID)
{
    m_nextScene = sceneID;
}
