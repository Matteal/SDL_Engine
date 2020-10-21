#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <fstream>


class toolbox
{
    public:
        toolbox();
        ~toolbox();
        static void Write(char* file, int charsize, TTF_Font* font, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer* renderer, const std::string &text, int width, int height, int posx, int posy);
        static void Write(char* file, int charsize, TTF_Font* font, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer* renderer, const std::string &text,int object, int width, int height, int posx, int posy);
        static void Write(char* file, int charsize, TTF_Font* font, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer* renderer, const std::string &text,const std::string &text2,int object, int width, int height, int posx, int posy);
        static void Write(char* file, int charsize, TTF_Font* font, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer* renderer, const std::string &text,const std::string &text2, int width, int height, int posx, int posy);
        static void Read();
        static void Push(std::string file,std::string pseudo);
        static std::string Pull(std::string file);

    protected:

    private:
};

#endif // TOOLBOX_H
