#ifndef INPUT_H
#define INPUT_H

// Include

#include <SDL.h>



// Classe

class Input
{
    public:

    Input();
    ~Input();

    void updateEvenements();
    bool terminer() const;

    //Gestion évènement
    bool getTouche(const SDL_Scancode touche) const;
    bool getBoutonSouris(const Uint8 bouton) const;
    bool mouvementSouris() const;

    // Getters curseur
    int getX() const;
    int getY() const;

    int getXRel() const;
    int getYRel() const;


    void afficherPointeur(bool reponse) const;
    void capturerPointeur(bool reponse) const;
    void SetTerminer(bool b);

    private:

    SDL_Event m_evenements;
    bool m_touches[SDL_NUM_SCANCODES];
    bool m_boutonsSouris[8];

    int m_x;
    int m_y;
    int m_xRel;
    int m_yRel;

    bool m_terminer;
};

#endif // INPUT_H
