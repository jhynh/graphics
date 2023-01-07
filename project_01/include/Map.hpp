#pragma once
#include <string>
class Map{
private:
//implementing tile system
/*     SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water; */

public:
    Map();
    ~Map();

    static void LoadMap(std::string path, int sizeX, int sizeY);
    //void DrawMap();

    //our 2d array
    int map[20][25];

};