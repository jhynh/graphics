#pragma once
#include "../Game.hpp"
#include "components.hpp"
#include "ECS.hpp"

class KeyboardController : public Component
{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    
    void init() override{
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    //needs a keyEvent for keyboard stuff
    void update()override{
        if(Game::event.type == SDL_KEYDOWN){
            switch(Game::event.key.keysym.sym){
            case SDLK_w:
                transform->velocity.y = -1;
                sprite->Play("Idle");
                break;
            case SDLK_a:
                transform->velocity.x = -1;
                sprite->Play("RunL");
                //for flipping
                //sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                sprite->Play("RunR");
                break;
            case SDLK_s:
                transform->velocity.y = 1;
                sprite->Play("Idle");
                break;
            default:
                break;
            }
        }
        if(Game::event.type == SDL_KEYUP){
            switch(Game::event.key.keysym.sym){
            case SDLK_w:
                transform->velocity.y = 0;
                sprite->Play("Idle");
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                sprite->Play("Idle");
                //reset flip
                //sprite->spriteFlip = SDL_FLIP_NONE;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                sprite->Play("Idle");
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                sprite->Play("Idle");
                break;
            
            case SDLK_ESCAPE:
                Game::isRunning = false;
            default:
                break;
            }
        }
    }
};
