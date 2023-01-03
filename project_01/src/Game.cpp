#include "Game.hpp"
#include "Texture_manager.hpp"
#include "Map.hpp"
#include "components.hpp"
#include "Vector2D.hpp"

Map* map;
Manager manager;

//NULLPTR haven't started sdl yet
SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int width, int height, bool fullscreen){
    //game loop
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initiated..." << std::endl;

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    
        if(window)
            std::cout << "window created!" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }else
        isRunning = false;

    //we need to init a surface, can remove after using search socrative texture
    map = new Map();

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("../assets/player.png");

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
    
    //map->LoadMap();       //for loading a config map
    manager.refresh();
    manager.update();

    player.getComponent<TransformComponent>().position.Add(Vector2D(5,0));

    if(player.getComponent<TransformComponent>().position.x > 500){
        player.getComponent<SpriteComponent>().setTex("../assets/slime.png");
    }

    std::cout << "updated: "<< count << " time(s).." << std::endl;
}

void Game::render(){
    //this is where we add stuff to render
    SDL_RenderClear(renderer);
    //use painted algorithm, layer rendering
    
    //source rect and destination rect
    //want to draw -> place to draw

    //SDL_RenderCopy(renderer, player_skin, NULL, &destR);
    map->DrawMap();

    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}