#include "SDL_Motor.h"
#include "SceneManager.h"
#include "TextureManager.h"

SDL_Motor::SDL_Motor() : m_window("Ouverture", 800, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED),
                    m_input(), m_renderer(nullptr), m_textureManager(m_window.getRenderer())
{
    // ctor
}

SDL_Motor::~SDL_Motor()
{
    //dtor
}


#include <windows.h>

bool SDL_Motor::init()
{
    if(!m_window.initWindow())
    {
        return false;
    }

    // Keep this after any renderer modification
    m_renderer = m_window.getRenderer();

    return true;
}

void SDL_Motor::mainloop()
{

    TextureManager tm(m_renderer);

    bool rt = true; //wtf is this?


    // Framerate variables
    unsigned int frameRate (1000 / 50);
    float debutBoucle(0), finBoucle(0), tempsEcoule(0);

    // Objets Scène
    SceneManager sceneM(m_renderer, tm);

    //défini le volume initial de la musique
    Mix_VolumeMusic(30);

    int lastSceneEntered = 0;

    Mix_PlayMusic(m_window.getMusic(1), -1 );

    SDL_StartTextInput();

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

        SDL_Event evt = m_input.getEvenement();
        while(SDL_PollEvent(&evt))
        {
            if(evt.type == SDL_KEYUP)
                m_input.SetTerminer(true);
        }

        // *** UPDATE ***

            if (m_input.getEvenement().type == SDL_TEXTINPUT)
            {
                //Append character
                if (rt)
                {
                    text += m_input.getEvenement().text.text;
                    rt = false;
                }
            }
            else
            {
                rt = true;
            }
            if (m_input.getTouche(SDL_SCANCODE_RETURN))
            {
                SDL_StopTextInput();
                toolbox::Push("data/pseudo.txt",text);
            }

        sceneM.update(&m_input);

        //update music
       // lastSceneEntered=m_input.getSelectedScene();


        // *** GRAPHICS ***

        // Clear the Canvas
        SDL_RenderClear(m_renderer);

        sceneM.render();
//        switch(m_input.getSelectedScene())
//        {
//            case 0:
//                {
//                    mainMenu.render();
//                    TTF_Font* p;
//                    toolbox::Write("data/police.ttf",18,p,255,255,255,m_renderer,text,100,100,310,200);
//                    break;
//                }
//            case 1:
//                pause.render();
//                break;
//            default:
//                std::cout<<"ON A TOUT PETEEEEEE !!!"<<std::endl;
//        }
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

// Cache le curseur quand activé
void SDL_Motor::afficherPointeur(bool reponse) const
{
    if(reponse)
        SDL_ShowCursor(SDL_ENABLE);

    else
        SDL_ShowCursor(SDL_DISABLE);
}

// Capture et cache le curseur quand activé
void SDL_Motor::capturerPointeur(bool reponse) const
{
    if(reponse)
        SDL_SetRelativeMouseMode(SDL_TRUE);

    else
        SDL_SetRelativeMouseMode(SDL_FALSE);
}
