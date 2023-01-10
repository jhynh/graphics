#include "gameObject.hpp"
#include "Texture_manager.hpp"
gameObject::gameObject(const char* texturesheet, int x, int y){
    objTexture = Texture_manager::LoadTexture(texturesheet);
    
    xPos = x;
    yPos = y;
}

//deals with movement of object
void gameObject::Update(){
    //these need to be set to be seen on the graph
    //xPos = 0;
    //yPos = 0;

    xPos++;
    yPos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void gameObject::Render(){
    //draws texture
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}