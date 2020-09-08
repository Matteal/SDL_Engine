#include <SDL2/SDL.h>
#include <iostream>

#include "Window.h"



int main(int argc, char **argv)
{
    // Création de la scène

    Window window("SDL2", 800, 500, SDL_WINDOW_SHOWN);

    // Initialisation de la scène
    window.initWindow();

    // Boucle Principale
    window.mainloop();


    return 0;
}
