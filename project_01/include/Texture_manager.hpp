#pragma once
#include "Game.hpp"

class Texture_manager{
public:
    //call as a class function rather than a member function, don't need an object to call it
        static SDL_Texture* LoadTexture(const char* fileName);
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};