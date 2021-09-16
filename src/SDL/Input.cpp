#include "Input.h"

Input::Input() : m_x(0), m_y(0), m_xRel(0), m_yRel(0), m_closeWindow(false)
{
    // Init m_key tab
    for(int i(0); i < SDL_NUM_SCANCODES; i++)
        m_keys[i] = false;


    // Init m_mouse[] tab
    for(int i(0); i < 8; i++)
        m_mouse[i] = false;
}

Input::~Input()
{
    //dtor
}

bool Input::clic()
{
    if ((SDL_MOUSEBUTTONDOWN) && (SDL_MOUSEBUTTONUP))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void Input::updateEvenements()
{
    // reset relative mouse coordinate to prevent fictional movement
    m_xRel = 0;
    m_yRel = 0;

    // reset vector
    if(!m_keyboardEvents.empty())
    {
        m_keyboardEvents.pop_back();
    }

    m_mouseEvents.clear();

    // Event loop
    while(SDL_PollEvent(&m_events))
    {

        switch(m_events.type)
        {

            // Pressed Key
            case SDL_KEYDOWN:
                m_keys[m_events.key.keysym.scancode] = true;
                m_keyboardEvents.push_back(m_events);
            break;

            // Released Key
            case SDL_KEYUP:
                m_keys[m_events.key.keysym.scancode] = false;
                m_keyboardEvents.push_back(m_events);
            break;



            // Mouse Button Pressed
            case SDL_MOUSEBUTTONDOWN:
                m_mouse[m_events.button.button] = true;
                m_mouseEvents.push_back(m_events.button.button);
            break;

            // Mouse Button Released
            case SDL_MOUSEBUTTONUP:
                m_mouse[m_events.button.button] = false;
                m_mouseEvents.push_back(m_events.button.button);
            break;


            // Mouse Motion
            case SDL_MOUSEMOTION:
                m_x = m_events.motion.x;
                m_y = m_events.motion.y;

                m_xRel = m_events.motion.xrel;
                m_yRel = m_events.motion.yrel;
            break;


            // Window is closed by user
            case SDL_WINDOWEVENT:
                if(m_events.window.event == SDL_WINDOWEVENT_CLOSE)
                    m_closeWindow = true;
            break;

            default:
            break;
        }
    }
}

bool Input::getKey(const SDL_Scancode key) const
{
    return m_keys[key];
}

SDL_Event Input::getEvent() const
{
    return m_events;
}

// Check if a Key has been Updated
bool Input::isKeyboardEvent(const SDL_Scancode scancode) const
{
    for(unsigned int i=0; i<m_mouseEvents.size(); i++)
    {
        if(m_keyboardEvents[i].key.keysym.scancode == scancode)
            return true;
    }
    return false;
}

//Get last Key Event
SDL_Scancode Input::getPressedKeys()
{
    if(!m_keyboardEvents.empty() && m_keyboardEvents.back().type == SDL_KEYDOWN)
        return m_keyboardEvents.back().key.keysym.scancode;
    else
        return SDL_SCANCODE_POWER;
}

//get last mouse Event
bool Input::isMouseEvent(const Uint8 scancode) const
{
    for(unsigned i=0; i<m_mouseEvents.size(); i++)
    {
        if(m_mouseEvents[i]==scancode)
            return true;
    }
    return false;
}

bool Input::getMouseButton(const Uint8 bouton) const
{
    return m_mouse[bouton];
}

bool Input::isMouseMoving() const
{
    if(m_xRel == 0 && m_yRel == 0)
        return false;

    else
        return true;
}


// Cursor Position
int Input::getX() const
{
    return m_x;
}

int Input::getY() const
{
    return m_y;
}

int Input::getXRel() const
{
    return m_xRel;
}

int Input::getYRel() const
{
    return m_yRel;
}



bool Input::isWindowClosed() const
{
    return m_closeWindow;
}

void Input::SetCloseWindow (bool b)
{
    m_closeWindow = b;
}

