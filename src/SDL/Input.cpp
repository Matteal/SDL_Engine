#include "Input.h"

Input::Input() : m_x(0), m_y(0), m_xRel(0), m_yRel(0), m_terminer(false), m_selectedScene(0)
{
    // Initialisation du tableau m_touches[]

    for(int i(0); i < SDL_NUM_SCANCODES; i++)
        m_touches[i] = false;


    // Initialisation du tableau m_boutonsSouris[]

    for(int i(0); i < 8; i++)
        m_boutonsSouris[i] = false;

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

    // Pour éviter des mouvements fictifs de la souris, on réinitialise les coordonnées relatives
    m_xRel = 0;
    m_yRel = 0;

    //réinitialiser les vectors
    if(!m_keyboardEvents.empty())
    {
        m_keyboardEvents.pop_back();
    }

    m_mouseEvents.clear();

    //boucle d'évènements
    while(SDL_PollEvent(&m_evenements))
    {

        switch(m_evenements.type)
        {

            // Cas d'une touche enfoncée
            case SDL_KEYDOWN:
                m_touches[m_evenements.key.keysym.scancode] = true;
                m_keyboardEvents.push_back(m_evenements);
            break;

            // Cas d'une touche relâchée
            case SDL_KEYUP:
                m_touches[m_evenements.key.keysym.scancode] = false;
                m_keyboardEvents.push_back(m_evenements);
            break;



            // Cas de pression sur un bouton de la souris
            case SDL_MOUSEBUTTONDOWN:
                m_boutonsSouris[m_evenements.button.button] = true;
                m_mouseEvents.push_back(m_evenements.button.button);
            break;

            // Cas du relâchement d'un bouton de la souris
            case SDL_MOUSEBUTTONUP:
                m_boutonsSouris[m_evenements.button.button] = false;
                m_mouseEvents.push_back(m_evenements.button.button);
            break;


            // Cas d'un mouvement de souris
            case SDL_MOUSEMOTION:
                m_x = m_evenements.motion.x;
                m_y = m_evenements.motion.y;

                m_xRel = m_evenements.motion.xrel;
                m_yRel = m_evenements.motion.yrel;
            break;


            // Cas de la fermeture de la fenêtre
            case SDL_WINDOWEVENT:
                if(m_evenements.window.event == SDL_WINDOWEVENT_CLOSE)
                    m_terminer = true;
            break;

            default:
            break;
        }
    }
}

bool Input::getTouche(const SDL_Scancode touche) const
{
    return m_touches[touche];
}

SDL_Event Input::getEvenement() const
{
    return m_evenements;
}

bool Input::isKeyboardEvent(const SDL_Scancode scancode) const
{
    for(unsigned int i=0; i<m_mouseEvents.size(); i++)
    {
        if(m_keyboardEvents[i].key.keysym.scancode == scancode)
            return true;
    }
    return false;
}

SDL_Scancode Input::getPressedKeys()
{
    if(!m_keyboardEvents.empty() && m_keyboardEvents.back().type == SDL_KEYDOWN)
        return m_keyboardEvents.back().key.keysym.scancode;
    else
        return SDL_SCANCODE_POWER;
}

bool Input::isMouseEvent(const Uint8 scancode) const
{
    for(unsigned i=0; i<m_mouseEvents.size(); i++)
    {
        if(m_mouseEvents[i]==scancode)
            return true;
    }
    return false;
}

bool Input::getBoutonSouris(const Uint8 bouton) const
{
    return m_boutonsSouris[bouton];
}

bool Input::mouvementSouris() const
{
    if(m_xRel == 0 && m_yRel == 0)
        return false;

    else
        return true;
}


// Getters concernant la position du curseur

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



bool Input::terminer() const
{
    return m_terminer;
}

void Input::SetTerminer (bool b)
{
    m_terminer = b;
}

