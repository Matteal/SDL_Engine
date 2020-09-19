#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"

#define NB_IMAGE 2

class Sprite
{
    public:
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture);
        Sprite(SDL_Renderer* renderer, SDL_Texture* texture, int w, int h, int posx, int posy);
        ~Sprite();

        void setDimensions(int dimensionX, int DimensionY);
        void setPosition(int PositionX, int PositionY);

        SDL_Rect* getSDL_Rect();
        bool estTouche(int curseurx, int curseury, bool bool1, bool bool2);

        void render();

    protected:

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;

        SDL_Rect m_rect;

        bool m_visible;

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
