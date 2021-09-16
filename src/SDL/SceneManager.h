#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

#define MAX_SCENE 4

class SceneManager
{
    public:
        SceneManager(SDL_Renderer* renderer, TextureManager&);
        ~SceneManager();

        void changeRatio(SDL_Window* window);
        void render();
        void update(Input* input);

    protected:

    private:
        Scene* m_tabScene[MAX_SCENE];
        int m_selectedScene;
        int m_nextScene;


        float m_ratioX, m_ratioY;
};

#endif // SCENEMANAGER_H
