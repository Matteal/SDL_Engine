#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Scene.h"

class MainScene: public Scene
{
    public:
        MainScene (SDL_Renderer* renderer, TextureManager&, MusicManager);

        int update(Input* input);
        //void render();
    private:
        bool m_isClosing;
        bool m_canInterract;
        bool m_isAudioOn;

        float m_menuTranslation;
        int m_nextScene;
};

#endif // MAINSCENE_H
