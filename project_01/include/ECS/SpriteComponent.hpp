//responsible for drawing to screen

#pragma once
#include "components.hpp"
#include <SDL2/SDL.h>
#include "../Texture_manager.hpp"
#include "Animation.hpp"
#include <map>
#include "../AssetManager.hpp"

class SpriteComponent : public Component
{
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    //srcRect is the PNG and destRect is the output
    SDL_Rect srcRect, destRect;

    //default
    bool animated = false;
    int frames = 0;
    //delay between frames
    int speed = 100;


public:

    int animIndex = 0;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    std::map<std::string, Animation> animations;

    SpriteComponent() = default;
    SpriteComponent(std::string id){
        //creates sprite
        setTex(id);
    }
    
    SpriteComponent(std::string id, bool isAnimated){
        //creates sprite
        animated = isAnimated;

        Animation idle = Animation(0, 1, 100);
        Animation runR = Animation(1, 4, 200);
        Animation runL = Animation(2, 4, 200);

        animations.emplace("Idle", idle);
        animations.emplace("RunR", runR);
        animations.emplace("RunL", runL);
        
        Play("Idle");

        setTex(id);
    }
    
    ~SpriteComponent(){}

    void setTex(std::string id){
        texture = Game::assets->getTexture(id);
    }

    void init() override{
        transform = &entity->getComponent<TransformComponent>();


        srcRect.x = srcRect.y = 0;
        srcRect.w =  transform->width;
        srcRect.h = transform->height;
    }

    void update() override{

        //we shift the x position on the png
        if(animated){
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }
        //32 -> 64, y position
        // 1*32 2*32 3*32
        srcRect.y = animIndex * transform->height;

        //rectangle expects an int
        destRect.x = static_cast<int>(transform->position.x - Game::camera.x);
        destRect.y = static_cast<int>(transform->position.y - Game::camera.y);
        
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;

    }

    void draw() override{
        Texture_manager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void Play(const char* animName)
    {
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
    }

};