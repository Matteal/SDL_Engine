#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>


class Texture
{
    public:
        Texture();
        bool Charger(const std::string &chemin, SDL_Renderer* rendu);
        SDL_Texture* getTexture();

    protected:

    private:
        SDL_Texture* m_texture;


};

//class TextureArray
//{
//    public:
//        TextureArray();
//        ~TextureArray();
//
//        void loadTexture(int textureID, const char* fichierImage);
//        Texture* operator[](int textureID);
//
//    private:
//        std::vector<Texture*> m_TextureArray;
//        std::vector<int> m_TextureID;
//};

#endif // TEXTURE_H
