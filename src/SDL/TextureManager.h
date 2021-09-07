#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#define DATA_PATH "data/"

#include <SDL_image.h>

#include <string>
#include <map>

class TextureManager
{
    public:
        TextureManager(SDL_Renderer* renderer);
        ~TextureManager();

    protected:

    private:
        SDL_Renderer* m_renderer;
        std::map<std::string, SDL_Texture*> m_textureMap;
        void chargerTexture(const std::string &chemin);
};

#endif // TEXTUREMANAGER_H
