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

bool Button::estTouche(int curseurx,int curseury)
{
    if((curseurx < m_dimensions.w + m_dimensions.x) && (curseurx > m_dimensions.x) && (curseury < m_dimensions.h + m_dimensions.y) && (curseury > m_dimensions.y))
    {
      return true;
    }
    else
    {
        return false;
    }
}

