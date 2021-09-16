#include "SDL_Motor.h"
#include "SceneManager.h"
#include "TextureManager.h"

SDL_Motor::SDL_Motor() : m_window("Ouverture", 800, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED),
                    m_input(), m_renderer(nullptr), m_textureManager(m_window.getRenderer())
{
    //ctor
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
        std::cout << "bug" << std::endl;
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
    m_textureArray[6] = chargerTexture("data/bgMenu.png",m_window.getRenderer());
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
    m_textureArray[25] = chargerTexture("data/cruiser.png",m_window.getRenderer());
    m_textureArray[26] = chargerTexture("data/cruiserAlt.png",m_window.getRenderer());
    m_textureArray[27] = chargerTexture("data/armored.png",m_window.getRenderer());
    m_textureArray[28] = chargerTexture("data/armoredAlt.png",m_window.getRenderer());
    m_textureArray[29] = chargerTexture("data/raider.png",m_window.getRenderer());
    m_textureArray[30] = chargerTexture("data/raiderAlt.png",m_window.getRenderer());

    // Tiles
    m_textureArray[35] = chargerTexture("data/Tiles/tileOutline.png",m_window.getRenderer());
    m_textureArray[36] = chargerTexture("data/Tiles/tileOutline1.png",m_window.getRenderer());
    m_textureArray[37] = chargerTexture("data/Tiles/tileOutline2.png",m_window.getRenderer());
    m_textureArray[38] = chargerTexture("data/Tiles/tile1.png",m_window.getRenderer());
    m_textureArray[39] = chargerTexture("data/Tiles/tile2.png",m_window.getRenderer());
    m_textureArray[40] = chargerTexture("data/Tiles/tile3.png",m_window.getRenderer());
    m_textureArray[41] = chargerTexture("data/Tiles/tile4.png",m_window.getRenderer());
    m_textureArray[42] = chargerTexture("data/Tiles/tileIsland1.png",m_window.getRenderer());

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
    Mix_VolumeMusic(0);

    int lastSceneEntered = 0;

    Mix_PlayMusic(m_window.getMusic(1), -1 );

    SDL_StartTextInput();

    // Core Loop
    while(!m_input.terminer())
    {
        int w, h;
    SDL_GetWindowSize(m_window.m_window, &w, &h);
    //std::cout<< w << " : " << h << std::endl;
        // Defining timestamp
        debutBoucle = SDL_GetTicks();


        // *** Managing Events ***
        m_input.updateEvenements();

        // Close the window when asked
        if(m_input.getTouche(SDL_SCANCODE_ESCAPE))
        {
            m_input.SetTerminer(true);
            //SDL_SetWindowSize(m_window.m_window,800,500);
            //SDL_SetWindowPosition(m_window.getWindow(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
        }

        if (m_input.getTouche(SDL_SCANCODE_F11) && !m_window.fullscreen)
        {
                std::cout << "out" << std::endl;
                SDL_SetWindowMaximumSize(m_window.getWindow(),800,1001);
                m_window.fullscreen = true;
        }
        else
        {
                std::cout << "in" << std::endl;
                SDL_SetWindowFullscreen(m_window.getWindow(),SDL_WINDOW_FULLSCREEN_DESKTOP);
                m_window.fullscreen = false;
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

Window SDL_Motor::getWindow()
{
    return m_window;
}
