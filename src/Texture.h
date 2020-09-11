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
<<<<<<< HEAD
        bool Charger(const std::string &chemin, SDL_Renderer* rendu);
        SDL_Texture* getTexture();
=======
        static SDL_Texture* Charger(const std::string &chemin, SDL_Renderer* rendu);
>>>>>>> dev-Colep

    protected:

    private:
<<<<<<< HEAD
        SDL_Texture* m_texture;
=======
>>>>>>> dev-Colep


};

<<<<<<< HEAD
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

=======
>>>>>>> dev-Colep
#endif // TEXTURE_H
