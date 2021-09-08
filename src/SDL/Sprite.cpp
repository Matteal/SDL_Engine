#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int x1, int y1, int x2, int y2, SDL_Texture* texture_toggle) : m_renderer(renderer), m_texture(texture), m_texture_toggle(texture_toggle), m_rect({x1, y1, x2, y2}), m_visible(true), m_toggle(false)
{
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    }
    ScreenHeight = dm.h;
    ScreenWidth = dm.w;
}

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture): m_renderer(renderer), m_texture(texture), m_visible(true)
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

void Sprite::setTexture(SDL_Texture* texture)
{
    m_texture = texture;
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

void Sprite::setVisible(bool visible)
{
    m_visible = visible;
}

void Sprite::render()
{
    if(m_visible)
    {
        if(m_toggle && m_texture_toggle != NULL)
        {
            SDL_RenderCopy(m_renderer,m_texture_toggle,NULL,&m_rect);
        }else
        {
            SDL_RenderCopy(m_renderer,m_texture,NULL,&m_rect);
        }
    }
}

void Sprite::ScreenSize()
{

}

