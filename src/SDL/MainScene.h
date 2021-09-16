#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "Scene.h"

class MainScene: public Scene
{
    public:
    MainScene (SDL_Renderer* renderer, TextureManager&);

        int update(Input* input);
    private:
        bool m_isAudioOn;
};

#endif // MAINSCENE_H
