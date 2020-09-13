#include <SDL.h>
#include <iostream>

#include "src/SDL_Motor.h"
#include "src/Window.h"



int main(int argc, char **argv)
{
    Window window("SDL2", 800, 500, SDL_WINDOW_SHOWN);

    // Trying to initiate window
    if(!window.initWindow())
    {
        std::cout<<"Error found when trying to create a window"<<std::cout;
        return 0;
    }


    SDL_Motor motor(window.getRenderer());

    motor.mainloop();

    return 0;
}
