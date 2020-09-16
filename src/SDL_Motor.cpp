#include "SDL_Motor.h"

SDL_Motor::SDL_Motor() : m_window("Ouverture", 800, 500, SDL_WINDOW_SHOWN), m_input(), m_Window_renderer(),m_play(m_window.getRenderer(),250,100,300,50),m_quit(m_window.getRenderer(),250,300,300,50),m_button(m_window.getRenderer(),250,300,300,50)
{
    // ctor
}

SDL_Motor::~SDL_Motor()
{
    //dtor
}

void SDL_Motor::aff_Menu()
{
    // Clear the SDL_Renderer
        SDL_RenderClear(m_Window_renderer);
        SDL_SetRenderDrawColor(m_Window_renderer,0,255,255,255);

        // Render

        SDL_RenderCopy(m_Window_renderer,m_textureArray[0],NULL,m_play.getSDL_Rect());
        SDL_RenderCopy(m_Window_renderer,m_textureArray[1],NULL,m_quit.getSDL_Rect());
        SDL_RenderPresent(m_Window_renderer);
}

void SDL_Motor::aff_Scene()
{
    // Clear the SDL_Renderer
        SDL_SetRenderDrawColor(m_Window_renderer,0,255,255,255);
        SDL_RenderClear(m_Window_renderer);


        // Render
        SDL_SetRenderDrawColor(m_Window_renderer,255,0,0,0);
        SDL_RenderFillRect(m_Window_renderer,m_button.getSDL_Rect());

        SDL_RenderPresent(m_Window_renderer);
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

    // Keep this after any renderer modification
     m_Window_renderer = m_window.getRenderer();



    return true;
}

void SDL_Motor::mainloop()
{

    // Framerate variables
    unsigned int frameRate (1000 / 50);
    float debutBoucle(0), finBoucle(0), tempsEcoule(0);

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
        if( Mix_PlayingMusic() == 0 )
        {
            //Play the music & manage the music
            Mix_VolumeMusic(30);
            Mix_PlayMusic(m_window.getMusic(), -1 );
        }



        // *** GRAPHICS ***
        if(m_input.Change())
        {
            aff_Scene();
        }
        else
        {
            aff_Menu();
        }





        if(m_play.estTouche(m_input.getX(),m_input.getY()))
        {
           if (m_input.getBoutonSouris(SDL_MOUSEBUTTONDOWN))
           {
                m_input.SetChange(true);
           }
        }
        else if (m_quit.estTouche(m_input.getX(),m_input.getY()))
        {
           if (m_input.getBoutonSouris(SDL_MOUSEBUTTONDOWN))
           {
               SDL_Quit();
               m_input.SetTerminer(true);
           }
        }




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
