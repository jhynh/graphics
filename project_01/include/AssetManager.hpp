#pragma once
#include "ECS.hpp"
#include <map>
#include <string>
#include "Texture_manager.hpp"
#include "Vector2D.hpp"

class AssetManager{
public:
    AssetManager(Manager* man);
    ~AssetManager();

    //gameobjects
    void CreateProjectile(Vector2D pos,Vector2D vel, int range, int speed, std::string id);

    //Texture management
    void AddTexture(std::string id, const char* path);

    SDL_Texture* getTexture(std::string id);

private:
    Manager* manager;
    std::map<std::string, SDL_Texture*> textures;

};