#ifndef INPUT_H
#define INPUT_H

// Include

#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>


// Classe

class Input
{
    public:

    Input();
    ~Input();

    void updateEvenements();

    //Gestion évènement
    bool getKey(const SDL_Scancode key) const;
    bool getMouseButton(const Uint8 bouton) const;
    bool isMouseMoving() const;

    // Getters curseur
    int getX() const;
    int getY() const;

    int getXRel() const;
    int getYRel() const;

    bool isWindowClosed() const;
    void SetCloseWindow(bool b);
    bool clic();

    SDL_Event getEvent() const;
    bool isKeyboardEvent(const SDL_Scancode scancode) const;
    bool isMouseEvent(const Uint8 scancode) const;
    SDL_Scancode getPressedKeys();

    private:

    SDL_Event m_events;
    bool m_keys[SDL_NUM_SCANCODES];
    bool m_mouse[8];

    std::vector<int> m_mouseEvents;
    std::vector<SDL_Event> m_keyboardEvents;
    //std::vector<int> m_keyboardEventsBuffer;


    int m_x;
    int m_y;
    int m_xRel;
    int m_yRel;

    bool m_closeWindow;
};

#endif // INPUT_H
