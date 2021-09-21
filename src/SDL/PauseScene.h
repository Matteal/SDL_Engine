#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include "Scene.h"

class PauseScene : public Scene
{
    public:
        PauseScene(SDL_Renderer* renderer, TextureManager& m_textureMap, MusicManager);

        int update(Input* input);
        void setResumeScene(int sceneID);
        //void render();
    private:
        int m_nextScene;
        void actuSoundSettings(Input* input);
        const int m_offsetScaling;
        int m_cursorMusic;
        int m_cursorSFX;

        bool m_isClosing;
        float m_menuTranslation;
        bool m_animationOnMenu;
        float m_recordPos[9];
};

#endif // PAUSESCENE_H
