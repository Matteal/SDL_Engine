#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"


class Button
{
    public:
        Button();
        Button(SDL_Renderer* renderer, int w, int h, int posx, int posy);
        virtual ~Button();
        SDL_Rect* getSDL_Rect();

    protected:

    private:
        SDL_Renderer* m_renderer;
        SDL_Rect m_rect;
        SDL_Rect m_dimensions;
};

#endif // BUTTON_H
