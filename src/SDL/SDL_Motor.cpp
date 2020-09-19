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

    // Loading Textures
    m_textureArray[0] = chargerTexture("data/jouer.png",m_window.getRenderer());
    m_textureArray[1] = chargerTexture("data/quitter.png",m_window.getRenderer());
    m_textureArray[2] = chargerTexture("data/tile1.png",m_window.getRenderer());
    m_textureArray[3] = chargerTexture("data/tile2.png",m_window.getRenderer());
    m_textureArray[4] = chargerTexture("data/tile3.png",m_window.getRenderer());
    m_textureArray[5] = chargerTexture("data/tile4.png",m_window.getRenderer());
    m_textureArray[6] = chargerTexture("data/tileIsland1.png",m_window.getRenderer());
    m_textureArray[7] = chargerTexture("data/tileOutline2.png",m_window.getRenderer());
    m_textureArray[8] = chargerTexture("data/boat1.png",m_window.getRenderer());
    m_textureArray[9] = chargerTexture("data/hp.png",m_window.getRenderer());
    m_textureArray[10] = chargerTexture("data/hpEmpty.png",m_window.getRenderer());
    m_textureArray[11] = chargerTexture("data/bg.png",m_window.getRenderer());
    m_textureArray[12] = chargerTexture("data/fightMenu.png",m_window.getRenderer());
    m_textureArray[13] = chargerTexture("data/Spide2.png",m_window.getRenderer());
    
	m_textureArray[25] = chargerTexture("data/tileOutline.png",m_window.getRenderer());

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
