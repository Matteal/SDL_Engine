#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

#include "SDL.h"

#define NB_IMAGE 50

class Sprite
{
    public:
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture);
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int posx, int posy, int w, int h, SDL_Texture* texture_toggle = NULL);
        ~Sprite();

        void setDimensions(int dimensionX, int DimensionY);
        void setPosition(int PositionX, int PositionY);

        void setTexture(SDL_Texture* texture);

        SDL_Rect* getSDL_Rect();
        bool estTouche(int curseurx, int curseury);
        bool estTouche(int curseurx, int curseury, bool bool1, bool bool2);

        void setVisible(bool visible = true);

        void render();

        void ScreenSize();

        float ScreenWidth;
        float ScreenHeight;

    protected:

        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Texture* m_texture_toggle;

        SDL_Rect m_rect;

        bool m_visible;
        bool m_toggle;

        //SDL_Rect m_dimensions;
};

//class Button
//{
//    public:
//        Button();
//        Button(SDL_Renderer* renderer, int w, int h, int posx, int posy);
//        virtual ~Button();
//        SDL_Rect* getSDL_Rect();
//        bool estTouche(int curseurx, int curseury);
//
//    protected:
//
//    private:
//        SDL_Renderer* m_renderer;
//        SDL_Rect m_rect;
//        SDL_Rect m_dimensions;
//};

#endif // BUTTON_H
