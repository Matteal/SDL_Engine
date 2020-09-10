#include <SDL.h>
#include <iostream>

#include "src/Window.h"



int main(int argc, char **argv)
{
    // Création de la scène

    Window window("SDL2", 800, 500, SDL_WINDOW_SHOWN);

    window.Update();


    return 0;
}
