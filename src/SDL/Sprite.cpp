#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int x1, int y1, int x2, int y2, SDL_Texture* texture_toggle) : m_renderer(renderer), m_texture(texture), m_texture_toggle(texture_toggle), m_rect({x1, y1, x2, y2}), m_posX(x1), m_posY(y1), m_dimX(x2), m_dimY(y2), m_visible(true), m_toggle(false)
{
    //ctor
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
void Sprite::setDimensions(int dimensionX, int dimensionY)
{
    m_dimX = dimensionX;
    m_dimY = dimensionY;
}

void Sprite::setPosition(int positionX, int positionY)
{
    m_posX = positionX;
    m_posY = positionY;
}

void Sprite::actuSDL_Rect(float ratioX, float ratioY)
{
    m_rect = SDL_Rect{(int)(m_posX*ratioX), (int)(m_posY*ratioY), (int)(m_dimX*ratioX), (int)(m_dimY*ratioY)};
}

void Sprite::setTexture(SDL_Texture* texture)
{
    m_texture = texture;
}

SDL_Rect* Sprite::getSDL_Rect()
{
    return &m_rect;
}

bool Sprite::isTouched(int cursorX, int cursorY)
{
    return (cursorX < m_rect.w + m_rect.x) && (cursorX > m_rect.x) && (cursorY < m_rect.h + m_rect.y) && (cursorY > m_rect.y);
}

// Allow not
bool Sprite::isTouched(int cursorX, int cursorY, bool isDown, bool isUp)
{
    // if LeftClick pressed
    if (isDown)
    {
        if (isTouched(cursorX, cursorY))
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
            if(isTouched(cursorX, cursorY))
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
