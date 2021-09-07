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
    bool getTouche(const SDL_Scancode touche) const;
    bool getBoutonSouris(const Uint8 bouton) const;
    bool mouvementSouris() const;

    // Getters curseur
    int getX() const;
    int getY() const;

    int getXRel() const;
    int getYRel() const;

    bool terminer() const;
    void SetTerminer(bool b);
    bool clic();

    SDL_Event getEvenement() const;
    bool isKeyboardEvent(const SDL_Scancode scancode) const;
    bool isMouseEvent(const Uint8 scancode) const;


    private:

    SDL_Event m_evenements;
    bool m_touches[SDL_NUM_SCANCODES];
    bool m_boutonsSouris[8];

    std::vector<int> m_mouseEvents;
    std::vector<int> m_keyboardEvents;


    int m_x;
    int m_y;
    int m_xRel;
    int m_yRel;

    bool m_terminer;
    int m_selectedScene;
    /*  0 -> Main Menu
        1 -> Game Scene
        2 -> Pause Menu */
};

#endif // INPUT_H
