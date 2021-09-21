#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

#define MAX_SCENE 5

class SceneManager
{
    public:
        SceneManager(SDL_Renderer* renderer, TextureManager&, MusicManager&, SDL_Window* window);
        ~SceneManager();

        void changeRatio();
        void render();
        virtual void update(Input* input);

    protected:

    private:
        Scene* m_tabScene[MAX_SCENE];
        int m_selectedScene;
        int m_nextScene;
        SDL_Window* m_window;

        Uint32 timer;
        Uint32 start;


        float m_ratioX, m_ratioY;
};

#endif // SCENEMANAGER_H
