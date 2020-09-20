#ifndef BUTTON_H
#define BUTTON_H

#include "SDL2/SDL.h"

class Button
{
    public:
        Button(SDL_Renderer* renderer, int x1, int y1, int x2, int y2);
        virtual ~Button();

        draw(int cursorX, int cursorY);

    protected:

    private:
        SDL_Renderer* m_renderer;

        SDL_Rect m_dimensions;
};

#endif // BUTTON_H
