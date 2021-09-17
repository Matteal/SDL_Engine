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

bool SDL_Motor::init()
{
    if(!m_window.initWindow())
    {
        std::cout << "Window has not been successfully created" << std::endl;
        return false;
    }

    // Keep this after any renderer modification
    m_renderer = m_window.getRenderer();


    return true;
}

void SDL_Motor::mainloop()
{
    MusicManager mm;
    TextureManager tm(m_renderer);

    bool rt = true; //wtf is this?


    // Framerate variables
    unsigned int frameRate (1000 / 50);
    float debutBoucle(0), finBoucle(0), tempsEcoule(0);

    // Objets Scène
    SceneManager sceneM(m_renderer, tm, mm);

    //défini le volume initial de la musique


    SDL_StartTextInput();

    // Core Loop
    while(!m_input.isWindowClosed())
    {
        int w, h;
    SDL_GetWindowSize(m_window.m_window, &w, &h);
    //std::cout<< w << " : " << h << std::endl;
        // Defining timestamp
        debutBoucle = SDL_GetTicks();


        sceneM.changeRatio(m_window.m_window);

        // *** Managing Events ***
        m_input.updateEvenements();

        // Close the window when asked
        if(m_input.getKey(SDL_SCANCODE_ESCAPE))
        {
            m_input.SetCloseWindow(true);
        }

        if (m_input.getPressedKeys() == SDL_SCANCODE_F11 && m_window.fullscreen)
        {
            SDL_SetWindowFullscreen(m_window.getWindow(),0);
            m_window.fullscreen = false;
        }
        else if (m_input.getPressedKeys() == SDL_SCANCODE_F11 && !m_window.fullscreen)
        {
            SDL_SetWindowFullscreen(m_window.getWindow(),SDL_WINDOW_FULLSCREEN_DESKTOP);
            m_window.fullscreen = true;
        }

        if (m_input.getPressedKeys() == SDL_SCANCODE_F4)
        {
            m_musicManager.mute();
        }

        if(m_input.getPressedKeys() == SDL_SCANCODE_F2)
        {
            m_musicManager.lowerVolume();
        }

        if (m_input.getPressedKeys() == SDL_SCANCODE_F3)
        {
            m_musicManager.increaseVolume();
        }

        SDL_Event evt = m_input.getEvent();

        while(SDL_PollEvent(&evt))
        {
            if(evt.type == SDL_KEYUP)
                m_input.SetCloseWindow(true);
        }

        // *** UPDATE ***

            if (m_input.getEvent().type == SDL_TEXTINPUT)
            {
                //Append character
                if (rt)
                {
                    text += m_input.getEvent().text.text;
                    rt = false;
                }
            }
            else
            {
                rt = true;
            }
            if (m_input.getKey(SDL_SCANCODE_RETURN))
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

// Cache le curseur quand activé
void SDL_Motor::showPointer(bool answer) const
{
    if(answer)
        SDL_ShowCursor(SDL_ENABLE);

    else
        SDL_ShowCursor(SDL_DISABLE);
}

// Capture et cache le curseur quand activé
void SDL_Motor::capturePointer(bool answer) const
{
    if(answer)
        SDL_SetRelativeMouseMode(SDL_TRUE);

    else
        SDL_SetRelativeMouseMode(SDL_FALSE);
}

Window SDL_Motor::getWindow()
{
    return m_window;
}
