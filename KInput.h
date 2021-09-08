#ifndef KINPUT_H
#define KINPUT_H
#include "Input.h"


class KInput
{
    public:
        KInput(int maxlength, Input* input, SDL_Renderer* renderer, int charsize);
        void directWrite();
        void render();
        int getLength();


    protected:

    private:
        int m_maxlenght;
        Input* m_input;
        SDL_Renderer* m_renderer;
        int m_charsize;
};

#endif // KINPUT_H
