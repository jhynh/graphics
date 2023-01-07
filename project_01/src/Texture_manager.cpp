#include "Texture_manager.hpp"

//texture manager
SDL_Texture* Texture_manager::LoadTexture(const char* texture){

    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    
    SDL_FreeSurface(tmpSurface);
    
    return tex;
};

void Texture_manager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip){
    
    SDL_RenderCopyEx(Game::renderer,tex,&src,&dest, NULL, NULL, flip);
    

} 