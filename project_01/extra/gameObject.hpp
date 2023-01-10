#pragma once
#include "Game.hpp"
class gameObject{

private:
    int xPos,yPos;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

public:
    gameObject(const char* texturesheet, int x, int y);
    void Update();
    void Render();
    ~gameObject();
};