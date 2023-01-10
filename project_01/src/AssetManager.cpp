#include "AssetManager.hpp"
#include "components.hpp"
AssetManager::AssetManager(Manager* man): manager(man){}

AssetManager::~AssetManager(){}

void AssetManager::CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id){
	auto& projectile(manager->addEntity());
	projectile.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
	projectile.addComponent<SpriteComponent>(id, false);
	projectile.addComponent<ProjectileComponent>(range, speed, vel);
	projectile.addComponent<ColliderComponent>("projectile");
	projectile.addGroup(Game::groupProjectiles);
}

void AssetManager::AddTexture(std::string id, const char* path)
{
    std::cout << id << ": " << path << std::endl;
    textures.emplace(id, Texture_manager::LoadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id)
{
    return textures[id];
}