#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int x1, int y1, int x2, int y2, SDL_Texture* texture_toggle) : m_renderer(renderer), m_texture(texture), m_texture_toggle(texture_toggle), m_rect({x1, y1, x2, y2}), m_posX(x1), m_posY(y1), m_dimX(x2), m_dimY(y2), m_visible(true), m_toggle(false)
{
    //ctr
}

Sprite::Sprite(SDL_Renderer* renderer, SDL_Texture* texture): m_renderer(renderer), m_texture(texture), m_visible(true)
{
    //ctor
    std::cout << "Destroy" << std::endl;
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

void Sprite::getDimensions(int& dimensionX, int& dimensionY)
{
    dimensionX = m_dimX;
    dimensionY = m_dimY;
}

void Sprite::setPosition(int positionX, int positionY)
{
    m_posX = positionX;
    m_posY = positionY;
}

void Sprite::getPosition(int& positionX, int& positionY)
{
    positionX = m_posX;
    positionY = m_posY;
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

bool Sprite::isClicked(Input* input)
{
    return (input->getMouseButton(SDL_BUTTON_LEFT) && input->isMouseEvent(SDL_BUTTON_LEFT) && isTouched(input->getX(), input->getY()));
}

void Sprite::setVisible(bool visible)
{
    m_visible = visible;
}

void Sprite::render(double Anglerotation)
{
    if(m_visible)
    {
        if(m_toggle && m_texture_toggle != NULL)
        {
            SDL_RenderCopy(m_renderer,m_texture_toggle,NULL,&m_rect);
        }else
        {
            //SDL_Point center = {m_rect.x - (m_rect.w)/2, m_rect.y - m_rect.h/2};
            SDL_Point center = {(m_rect.w)/2, (m_rect.h)/2};
            SDL_RenderCopyEx(m_renderer,m_texture,NULL,&m_rect, Anglerotation, &center, SDL_FLIP_NONE);
        }
    }
}

bool Sprite::Intersect(Sprite* sprite1, Sprite* sprite2)
{
    // recup info sprite1
    int p1x, p1y, p2x, p2y;
    sprite1->getPosition(p1x, p1y);
    sprite1->getDimensions(p2x, p2y);
    p2x += p1x;
    p2y += p1y;

    // recup info sprite2
    int q1x, q1y, q2x, q2y;
    sprite2->getPosition(q1x, q1y);
    sprite2->getDimensions(q2x, q2y);
    q2x += q1x;
    q2y += q1y;

    //no overlap
    if(p1x == p2x || p1y == p2y || q1x == q2x || q1y == q2y)
    {
        //asert this never append
        return false;
    }

    // If one rectangle is on a side of other
    if (p1x >= q2x || q1x >= p2x)

    {
        return false;
    }

    if(p2y <= q1y || q2y <= p1y)
    {
        return false;
    }

    return true;
}
