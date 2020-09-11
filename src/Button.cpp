#include "Button.h"

Button::Button(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) : m_renderer(renderer), m_dimensions({x1, y1, x2, y2})
{
    //ctor
}

Button::~Button()
{
    //dtor
}

SDL_Rect* Button::getSDL_Rect()
{

    return &m_dimensions;
}

