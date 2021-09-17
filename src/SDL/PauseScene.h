#ifndef PAUSESCENE_H
#define PAUSESCENE_H
#include "Scene.h"

class PauseScene : public Scene
{
    public:
        PauseScene(SDL_Renderer* renderer, TextureManager& m_textureMap, MusicManager);

        int update(Input* input);
        void render();
};

#endif // PAUSESCENE_H
