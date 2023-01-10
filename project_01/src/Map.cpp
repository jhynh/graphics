#include "Map.hpp"
#include "Game.hpp"
#include "ECS.hpp"
#include "components.hpp"   //MAKE SURE INCLUDES ARE RIGHT!!!!
#include <fstream>

//defined somewhere else (diff between extern and forward declare)
extern Manager manager;

/*
    water = 0
    dirt = 1
    grass = 2
*/
Map::Map(std::string tID, int ms, int ts) : texID(tID), mapScale(ms), tileSize(ts)
{
    scaledSize = ms * ts;
}

Map::~Map(){
/*     SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt); */
}

void Map::LoadMap(std::string path, int sizeX, int sizeY){

    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    int srcX, srcY;

    for(int y = 0; y < sizeY; ++y){
        for(int x = 0; x < sizeX; ++x){
            mapFile.get(tile);
            srcY = atoi(&tile) * tileSize;
            mapFile.get(tile);
            srcX = atoi(&tile) * tileSize;
            //taking a pointer and a pointer passes a reference so we can just take reference...
            AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
            mapFile.ignore(2, ',');
        }
        //mapFile.ignore(); //odd that this doesn't JUST get rid of the \n at the end
    }
    for(int y = 0; y<sizeY; ++y){
        for(int x = 0; x<sizeX; ++x){
            mapFile.get(tile);
            if(tile == '1'){
                auto& tcol(manager.addEntity());
                tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
                tcol.addGroup(Game::groupColliders);
            }
            mapFile.ignore(2, ',');
        }
    }

    mapFile.close();
}

void Map::AddTile(int srcX, int srcY,int xpos, int ypos)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, texID);
    tile.addGroup(Game::groupMap);
}