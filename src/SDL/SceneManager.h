#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

#define MAX_SCENE 4

class SceneManager
{
    public:
        SceneManager(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]);
        ~SceneManager();

        void render();
        void update(Input* input);

    protected:

    private:
        Scene* m_tabScene[MAX_SCENE];
        int m_selectedScene;
};

#endif // SCENEMANAGER_H
