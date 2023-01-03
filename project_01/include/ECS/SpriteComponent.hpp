#pragma once

#include "components.hpp"
#include <SDL2/SDL.h>
#include "Texture_manager.hpp"

class SpriteComponent : public Component
{
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        //creates sprite
        setTex(path);
    }

    void setTex(const char* path){
        texture = Texture_manager::LoadTexture(path);
    }

    void init() override{
        transform = &entity->getComponent<TransformComponent>();


        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }

    void update() override{
        //rectangle expects an int
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;

    }

    void draw() override{
        Texture_manager::Draw(texture, srcRect, destRect);
    }

};