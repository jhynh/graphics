#include "Map.hpp"
#include "Game.hpp"
#include <fstream>

/*
    water = 0
    dirt = 1
    grass = 2

    for visual representation, can be put into a config file, external text, xml, and pass it in to load a map
*/
/* int lvl1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
};
 */
Map::Map(){
/*     dirt = Texture_manager::LoadTexture("../assets/dirt.png");
    grass = Texture_manager::LoadTexture("../assets/grass.png");
    water = Texture_manager::LoadTexture("../assets/water.png");

    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;


    dest.x = dest.y = 0; */

    

}

Map::~Map(){
/*     SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt); */
}

void Map::LoadMap(std::string path, int sizeX, int sizeY){
/*     for(int row=0; row<20;++row){
        for(int col=0; col<25;++col){
            map[row][col] = arr[row][col];
        }
    } */

    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    for(int y = 0; y < sizeY; ++y){
        for(int x = 0; x < sizeX; ++x){
            mapFile.get(tile);
            //taking a pointer and a pointer passes a reference so we can just take reference...
            Game::AddTile(atoi(&tile), x * 32, y * 32);
            mapFile.ignore(2,',');
        }
        //mapFile.ignore(); odd that this doesn't JUST get rid of the \n at the end
    }

    mapFile.close();
}




/* void Map::DrawMap(){
    int type = 0;
    for(int row=0; row<20;++row){
        for(int col=0; col<25;++col){
            type = map[row][col];
            
            dest.x = col * 32;
            dest.y = row * 32;

            switch(type){
            case 0:
                Texture_manager::Draw(water,src,dest);
                break;
            case 1:
                Texture_manager::Draw(dirt,src,dest);
                break;
            case 2:
                Texture_manager::Draw(grass,src,dest);
                break;
            default:
                break;
            };
        }
    }
} */