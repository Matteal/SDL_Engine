#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

#include "SDL.h"


class Sprite
{
    public:
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture);
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int posx, int posy, int w, int h, SDL_Texture* texture_toggle = NULL);
        ~Sprite();

        void setDimensions(int dimensionX, int dimensionY);
        void setPosition(int positionX, int positionY);
        void actuSDL_Rect(float ratioX, float ratioY);

        void setTexture(SDL_Texture* texture);

        SDL_Rect* getSDL_Rect();
        bool isTouched(int cursorX, int cursorY);
        bool isTouched(int cursorX, int cursorY, bool bool1, bool bool2);

        void setVisible(bool visible = true);

        void render();

        float ScreenWidth;
        float ScreenHeight;

    protected:

        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Texture* m_texture_toggle;

        SDL_Rect m_rect;

        int m_posX, m_posY;
        int m_dimX, m_dimY;

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
