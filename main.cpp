#include <SDL.h>
#include <iostream>

#include "src/SDL/SDL_Motor.h"
#include "src/SDL/Window.h"
#include "math.h"


int main(int argc, char **argv)
{
    SDL_Motor motor;

    // If an error occur during the init phase
    if(!motor.init())
    {
        std::cout << "Initialisation Failed" << std::endl;
        std::cout << "Ending program ..." << std::endl;
        return 0;
    }

    motor.mainloop();

    return 0;
}
