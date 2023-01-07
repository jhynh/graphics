#include "Game.hpp"
#include "Texture_manager.hpp"
#include "Map.hpp"
#include "components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

Map* map;                                                                   //creating a ptr of obj map
Manager manager;                                                            //creating a manager object

//NULLPTR haven't started sdl yet
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

//clearly define groups
enum groupLabels : std::size_t{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders,
};

//implementing tile system
/* auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity()); */

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

//spawn stuff
//-------------------------------------------------------------------------------------------------------
    //we need to init a surface, can remove after using search socrative texture
    map = new Map();

    Map::LoadMap("../assets/p16x16.map", 16, 16);

//implmeneting tile system
/*     tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
    tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
    tile1.addComponent<ColliderComponent>("dirt");
    tile2.addComponent<TileComponent>(150, 150, 32, 32, 2);
    tile2.addComponent<ColliderComponent>("grass"); */

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("../assets/player_anims.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

    //make wall bigger than a single title
    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("../assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);
//-------------------------------------------------------------------------------------------------------
}
//https://medium.com/@savas/nomad-game-engine-part-7-the-event-system-45a809ccb68f
void Game::handleEvents(){
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
    //map->LoadMap();       //for loading a config map
    manager.refresh();
    manager.update();

    for(auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render(){
    //this is where we add stuff to render
    SDL_RenderClear(renderer);
    //use painted algorithm, layer rendering
    //source rect and destination rect
    //want to draw -> place to draw
    //map->DrawMap();

    //this used to draw objs in order they were created, now using grouping method
    //manager.draw();

    for(auto& t : tiles){
        t->draw();
    }
    for(auto& p : players){
        p->draw();
    }
    for(auto& e : enemies){
        e->draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::AddTile(int id, int x, int y){
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
}