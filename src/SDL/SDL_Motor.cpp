#include "SDL_Motor.h"

SDL_Motor::SDL_Motor() : m_window("Ouverture", 800, 500, SDL_WINDOW_SHOWN), m_input(), m_renderer() //add flag  | SDL_WINDOW_FULLSCREEN
{
    // ctor
}

SDL_Motor::~SDL_Motor()
{
    //dtor
}



bool SDL_Motor::init()
{
    if(!m_window.initWindow())
    {
        return false;
    }

    // *** LOADING TEXTURES *** //

    // Buttons
    m_textureArray[0] = chargerTexture("data/buttonPlay.png",m_window.getRenderer());
    m_textureArray[1] = chargerTexture("data/buttonPlayAlt.png",m_window.getRenderer());
    m_textureArray[2] = chargerTexture("data/buttonQuit.png",m_window.getRenderer());
    m_textureArray[3] = chargerTexture("data/buttonQuitAlt.png",m_window.getRenderer());
    m_textureArray[4] = chargerTexture("data/audioOn.png",m_window.getRenderer());
    m_textureArray[5] = chargerTexture("data/audioOff.png",m_window.getRenderer());
    // 6 - Menu background

    // Fight Images
    m_textureArray[9] = chargerTexture("data/hp.png",m_window.getRenderer());
    m_textureArray[10] = chargerTexture("data/hpEmpty.png",m_window.getRenderer());
    m_textureArray[11] = chargerTexture("data/bg.png",m_window.getRenderer());
    m_textureArray[12] = chargerTexture("data/fightMenu.png",m_window.getRenderer());
    m_textureArray[13] = chargerTexture("data/fightMenu2.png",m_window.getRenderer());
    m_textureArray[14] = chargerTexture("data/fightStrike.png",m_window.getRenderer());
    m_textureArray[15] = chargerTexture("data/fightSurprise.png",m_window.getRenderer());
    m_textureArray[16] = chargerTexture("data/fightDefend.png",m_window.getRenderer());

    // Ships
    m_textureArray[25] = chargerTexture("data/boat1L.png",m_window.getRenderer());
    m_textureArray[26] = chargerTexture("data/boat1R.png",m_window.getRenderer());
    m_textureArray[27] = chargerTexture("data/boat2L.png",m_window.getRenderer());
    m_textureArray[28] = chargerTexture("data/boat2R.png",m_window.getRenderer());

    // Tiles
    m_textureArray[35] = chargerTexture("data/Tiles/tileOutline.png",m_window.getRenderer());
    m_textureArray[36] = chargerTexture("data/Tiles/tileOutline2.png",m_window.getRenderer());
    m_textureArray[37] = chargerTexture("data/Tiles/tile1.png",m_window.getRenderer());
    m_textureArray[38] = chargerTexture("data/Tiles/tile2.png",m_window.getRenderer());
    m_textureArray[39] = chargerTexture("data/Tiles/tile3.png",m_window.getRenderer());
    m_textureArray[40] = chargerTexture("data/Tiles/tile4.png",m_window.getRenderer());
    m_textureArray[41] = chargerTexture("data/Tiles/tileIsland1.png",m_window.getRenderer());

    // Keep this after any renderer modification
    m_renderer = m_window.getRenderer();



    return true;
}

void SDL_Motor::mainloop()
{

    // Framerate variables
    unsigned int frameRate (1000 / 50);
    float debutBoucle(0), finBoucle(0), tempsEcoule(0);

    // Objets Scène
    MainMenu mainMenu(m_renderer, m_textureArray);
    PauseMenu pause(m_renderer, m_textureArray);
    GameTile gameT(m_renderer, m_textureArray);
    GameFight gameF(m_renderer, m_textureArray);

    //défini le volume initial de la musique
    Mix_VolumeMusic(30);


    // Core Loop
    while(!m_input.terminer())
    {

        // Defining timestamp
        debutBoucle = SDL_GetTicks();


        // *** Managing Events ***
        m_input.updateEvenements();

        // Close the window when asked
        if(m_input.getTouche(SDL_SCANCODE_ESCAPE))
        {
            m_input.SetTerminer(true);
        }


        // TODO : Move the music section into each Scene::update
        if( Mix_PlayingMusic() == 0 )
        {
            //Play the music & manage the music
            Mix_PlayMusic(m_window.getMusic(), -1 );

        }


        // *** UPDATE ***

        switch(m_input.getSelectedScene())
        {
            case 0:
                mainMenu.update(&m_input);
                break;
            case 1:
                pause.update(&m_input);
                break;
            case 2:
                gameT.update(&m_input);
                break;
            case 3:
                gameF.update(&m_input);
                break;
            default:
                std::cout<<"ON A TOUT PETEEEEEE !!!"<<std::endl;
        }



        // *** GRAPHICS ***

        // Clear the Canvas
        SDL_RenderClear(m_renderer);

        switch(m_input.getSelectedScene())
        {
            case 0:
                mainMenu.render();
                break;
            case 1:
                pause.render();
                break;
            case 2:
                gameT.render();
                break;
            case 3:
                gameF.render();
                break;
            default:
                std::cout<<"ON A TOUT PETEEEEEE !!!"<<std::endl;
        }

        // Print the Canvas
        SDL_RenderPresent(m_renderer);



        // *** FRAMERATE ***

        // Calcul du temps écoulé
        finBoucle = SDL_GetTicks();
        tempsEcoule = finBoucle - debutBoucle;
        //std::cout<< tempsEcoule <<std::endl;

        // Si nécessaire, on met en pause le programme
        if(tempsEcoule < frameRate)
            SDL_Delay(frameRate - tempsEcoule);
    }

}



SDL_Texture* chargerTexture(const std::string &chemin, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(chemin.c_str());
    if (surface == NULL)
    {
        std::cout << "Erreur de chargement de surface " <<std::endl;
        return NULL;
    }
    else
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        return texture;
    }
}
