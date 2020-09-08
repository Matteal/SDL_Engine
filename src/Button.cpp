#include "Button.h"

Button::Button(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) : m_renderer(renderer), m_dimensions({x1, y1, x2, y2})
{
    //ctor
}

Button::~Button()
{
    //dtor
}

Button::draw(int cursorX, int cursorY)
{
    if(cursorX > m_dimensions.x && cursorY > m_dimensions.y && cursorX < m_dimensions.x + m_dimensions.w && cursorY < m_dimensions.y + m_dimensions.h)
    {
        // Overlay
        SDL_SetRenderDrawColor(m_renderer, 200, 50, 50, 255);
    }else
    {
        SDL_SetRenderDrawColor(m_renderer, 190, 0, 0, 255);
    }

    SDL_RenderFillRect(m_renderer, &m_dimensions);
}
