#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int x1, int y1, int x2, int y2) : m_renderer(renderer), m_texture(texture), m_rect({x1, y1, x2, y2}), m_visible(true), m_toggle(false)
{
    //ctor
}

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture): m_renderer(renderer), m_texture(m_texture), m_visible(true)
{
    //ctor
}

Sprite::~Sprite()
{
    //dtor
}

//Re-size
void Sprite::setDimensions(int dimensionX, int DimensionY)
{
    m_rect = SDL_Rect{m_rect.x, m_rect.y, dimensionX, DimensionY};
}
void Sprite::setPosition(int PositionX, int PositionY)
{
    m_rect = SDL_Rect{PositionX, PositionY, m_rect.w, m_rect.h};
}

SDL_Rect* Sprite::getSDL_Rect()
{

    return &m_rect;
}

bool Sprite::estTouche(int curseurX, int curseurY)
{
    return (curseurX < m_rect.w + m_rect.x) && (curseurX > m_rect.x) && (curseurY < m_rect.h + m_rect.y) && (curseurY > m_rect.y);
}

// Allow not
bool Sprite::estTouche(int curseurX, int curseurY, bool isDown, bool isUp)
{
    // if LeftClick pressed
    if (isDown)
    {
        if (estTouche(curseurX, curseurY))
        {
            m_toggle = true;
        }
    }

    // if LeftClick release
    if (m_toggle)
    {
        if (isUp)
        {
            m_toggle = false;
            if(estTouche(curseurX, curseurY))
            {
                return true;
            }
        }
    }
    return false;
}

void Sprite::render()
{
    if(m_visible)
    {
        SDL_RenderCopy(m_renderer,m_texture,NULL,&m_rect);
    }
}



//
//Button::Button(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) : m_renderer(renderer), m_dimensions({x1, y1, x2, y2})
//{
//    //ctor
//}
//
//Button::~Button()
//{
//    //dtor
//}
//
//SDL_Rect* Button::getSDL_Rect()
//{
//
//    return &m_dimensions;
//}
//
//bool Button::estTouche(int curseurx,int curseury)
//{
//    if((curseurx < m_dimensions.w + m_dimensions.x) && (curseurx > m_dimensions.x) && (curseury < m_dimensions.h + m_dimensions.y) && (curseury > m_dimensions.y))
//    {
//      return true;
//    }
//    else
//    {
//        return false;
//    }
//    return false;
//}

