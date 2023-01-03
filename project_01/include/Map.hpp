#pragma once
#include "Game.hpp"

class Map{
private:
    SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

public:
    Map();
    ~Map();

    void LoadMap(int[20][25]);
    void DrawMap();

    //our 2d array
    int map[20][25];

};