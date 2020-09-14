#ifndef SCENE_H
#define SCENE_H
#include <SDL.h>


class Scene
{
    public:
        Scene(const char* m_title, const int m_width, const int m_height, const Uint32 m_flags);
        ~Scene();

        bool InitScene();
        SDL_Renderer* getRenderer();

    protected:

    private:
        const char* m_title;
        const int m_width;
        const int m_height;
        const Uint32 m_flags;

        SDL_Window* m_scene;
        SDL_Renderer* m_renderer;
};

#endif // SCENE_H
