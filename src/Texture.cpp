#include "Texture.h"


Texture::Texture() : m_texture(NULL)

{
    //ctor
}


bool Texture::Charger(const std::string &chemin, SDL_Renderer* rendu)
{
    SDL_Surface* surface = IMG_Load(chemin.c_str());
    //SDL_Texture* texture;
    if (surface == NULL)
    {
        std::cout << "Erreur de chargement de surface " <<std::endl;
        m_texture = NULL;
        return false;
    }
    else
    {
        m_texture = SDL_CreateTextureFromSurface(rendu,surface);
        SDL_FreeSurface(surface);
        return true;
    }
}

SDL_Texture* Texture::getTexture()
{
    return m_texture;
}



//* ***** TextureArray ***** */

//TextureArray::TextureArray()
//{
//
//}
//
//TextureArray::~TextureArray()
//{
//
//}
//
//void TextureArray::loadTexture(int textureID, const char* fichierImage)
//{
//    Texture* newTexture = new Texture(fichierImage);
//    if(newTexture->charger())
//    {
//        m_TextureArray.push_back(newTexture);
//        m_TextureID.push_back(textureID);
//    }
//    else
//    {
//        std::cout << "Erreur de chargement de la texture" << std::endl;
//    }
//}
//
//Texture* TextureArray::operator[](int textureID)
//{
//    int indice = 0;
//    for(auto &elem : m_TextureID)
//    {
//        if(elem == textureID)
//        {
//            return m_TextureArray[indice]->getPointer();
//        }
//        indice++;
//    }
//    std::cout << "Erreur : L'acces a la texture <" << textureID << "> est impossible";
//    return NULL;
//}

