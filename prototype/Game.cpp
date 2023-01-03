#include "Game.hpp"
SDL_Texture *player_skin;
SDL_Rect srcR, destR;
Game::Game(){

}

Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    //game loop
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initiated..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    
        if(window)
            std::cout << "window created!" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }else{
        isRunning = false;
    }

    //we need to init a surface, can remove after using search socrative texture
    SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
    player_skin = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update(){
    count++;
    destR.h = 64;
    destR.w = 52;
    destR.x = count;

    std::cout << "updated: "<< count << " times.." << std::endl;
}

void Game::render(){
    //this is where we add stuff to render
    SDL_RenderClear(renderer);
    //use painted algorithm, layer rendering
    
    //source rect and destination rect
    //want to draw -> place to draw
    SDL_RenderCopy(renderer, player_skin, NULL, &destR);
    
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}