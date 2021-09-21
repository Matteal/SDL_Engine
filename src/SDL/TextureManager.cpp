#include "TextureManager.h"

#include <iostream>


TextureManager::TextureManager(SDL_Renderer* renderer): m_renderer(renderer)
{
    //TODO: charger asynchroniquement les images
    loadTexture("Apparition_menu_1.png");
    loadTexture("Apparition_menu_2.png");
    loadTexture("Apparition_menu_3.png");
    loadTexture("Apparition_menu_4.png");
    loadTexture("Apparition_menu_5.png");
    loadTexture("Bouton_play_simple.png");
    loadTexture("Bouton_quit_chaines.png");
    loadTexture("Bouton_quit_simple.png");
    loadTexture("Bouton_settings_chaines.png");
    loadTexture("Bouton_settings_simple.png");
    loadTexture("Plaque_metal.jpg");

    loadTexture("chains.png");
    loadTexture("Bouton_play_overlay.png");
    loadTexture("Bouton_quit_overlay.png");
    loadTexture("Bouton_settings_overlay.png");
    loadTexture("menu_button_left.png");
    loadTexture("menu_button_right.png");
    loadTexture("Bouton_SFX.png");
    loadTexture("Bouton_Music.png");
    loadTexture("Bouton_Resume.png");
    loadTexture("scaling_cursor.png");

    loadTexture("Level1.jpg");
    loadTexture("Player.png");
    loadTexture("Workbench.png");
    loadTexture("Part_distributor1.png");
    loadTexture("Station1.png");
    loadTexture("Product_drop.png");

    loadTexture("Rotor.png");
    loadTexture("Motherboard.png");
    loadTexture("Screw.png");
    loadTexture("Cogwheel.png");
    loadTexture("Material.png");
    loadTexture("Computer.png");
    loadTexture("Engine.png");



}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::operator[](const std::string str)
{
    return m_textureMap[str];
}

void TextureManager::loadTexture(const std::string &path)
{

    SDL_Surface* surface = IMG_Load((DATA_PATH + path).c_str());
    if (surface == NULL)
    {
        std::cout << "An error occured during the surface loading ! " << path <<std::endl;
    }
    else
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);
        SDL_FreeSurface(surface);

        std::string name = path.substr(path.find_last_of('/')+1);
        name = name.substr(0, name.find('.'));

        m_textureMap[name] = texture;
    }
}

