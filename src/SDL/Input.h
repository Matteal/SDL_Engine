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


    bool terminer() const;
    void SetTerminer(bool b);
    bool clic();
    bool getRoundUP();
    bool getRoundDOWN();

    int getSelectedScene() const;
    void setSelectedScene(int select);


    private:

    SDL_Event m_evenements;
    bool m_touches[SDL_NUM_SCANCODES];
    bool m_boutonsSouris[8];

    int m_x;
    int m_y;
    int m_xRel;
    int m_yRel;

    bool m_terminer;
    bool m_DuringRoundUP;
    bool m_DuringRoundDOWN;
    int m_selectedScene;
    /*  0 -> Main Menu
        1 -> Game Scene
        2 -> Pause Menu */
};

#endif // INPUT_H
