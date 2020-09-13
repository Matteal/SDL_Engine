#include "SDL_Motor.h"

SDL_Motor::SDL_Motor(SDL_Renderer* renderer) : m_input(), m_renderer(renderer), m_play(renderer,250,100,300,50), m_quit(renderer,250,300,300,50)
{
//    m_window.initWindow();
//    m_renderer = m_window.getRenderer();

    // Loading Textures
    m_textureArray[0] = chargerTexture("data/jouer.png",m_renderer);
    m_textureArray[1] = chargerTexture("data/quitter.png",m_renderer);
}

SDL_Motor::~SDL_Motor()
{
    //dtor
}

void SDL_Motor::mainloop()
{

    //TODO: Move this
    SDL_SetRenderDrawColor(m_renderer,0,255,255,255);
    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer,m_textureArray[0],NULL,m_play.getSDL_Rect());
    SDL_RenderCopy(m_renderer,m_textureArray[1],NULL,m_quit.getSDL_Rect());
    SDL_RenderPresent(m_renderer);

    SDL_Delay(200);

    // Variables framerate
    unsigned int frameRate (1000 / 50);
    float debutBoucle(0), finBoucle(0), tempsEcoule(0);

    // Boucle principale
    while(!m_input.terminer())
    {
        //std::cout<<"Debug"<<std::endl;


        // On définit le temps de début de boucle
        debutBoucle = SDL_GetTicks();


        // *** Gestion des évènements ***
        m_input.updateEvenements();

        // Fermer la fenêtre
        if(m_input.getTouche(SDL_SCANCODE_ESCAPE))
        {
            bool b = true;
            m_input.SetTerminer(b);
        }
        // *** Affichage ***
        //SDL_RenderClear(m_renderer);





        // Affichage du renderer
        //SDL_SetRenderDrawColor(m_renderer, 0,0,0,0);





        // *** Framerate ***

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
