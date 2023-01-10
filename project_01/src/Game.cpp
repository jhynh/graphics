#include "Game.hpp"
#include "Texture_manager.hpp"
#include "Map.hpp"
#include "components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"
#include "AssetManager.hpp"

Map* map;                                                                   //creating a ptr of obj map
Manager manager;                                                            //creating a manager object

//NULLPTR haven't started sdl yet
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

//width, height
SDL_Rect Game::camera = {0,0,800,640};

AssetManager* Game::assets = new AssetManager(&manager);

bool Game::isRunning = false;

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

    assets->AddTexture("terrain", "../assets/terrain_ss.png");
    assets->AddTexture("player", "../assets/player_anims.png");
    assets->AddTexture("projectile", "../assets/fireball.png");

//spawn stuff
//-------------------------------------------------------------------------------------------------------
    //we need to init a surface, can remove after using search socrative texture
    map = new Map("terrain", 3, 32);

    map->LoadMap("../assets/map.map", 25, 20);

    player.addComponent<TransformComponent>(800.0f, 640.0f, 32 , 32, 4);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");                           //possibly due to the ordering of the components being added, causing the collider component to appear in the player texture
    player.addGroup(groupPlayers);
    
    assets->CreateProjectile(Vector2D(600,600),Vector2D(2,0), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600,620),Vector2D(2,1), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(400,600),Vector2D(2,-1), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600,660),Vector2D(2,0), 200, 2, "projectile");

//-------------------------------------------------------------------------------------------------------
}
//bro, stop making vectors of type double
auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));        //MISTAKES BRUH, YOU PUT IT IN THE WRONG GROUP
auto& projectiles(manager.getGroup(Game::groupProjectiles));

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

    SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player.getComponent<TransformComponent>().position;

    manager.refresh();
    manager.update();

    //check if player is colliding with it
    for(auto& c : colliders){
        SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
        if(Collision::AABB(cCol, playerCol)){
            player.getComponent<TransformComponent>().position = playerPos;
        }
    }

    for(auto& p : projectiles)
    {
        if(Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            std::cout << "Hit the player\n";
            p->destroy();
        }
    }

//*************************************************************************->for side scrolling
/*     Vector2D pVel = player.getComponent<TransformComponent>().velocity;
    int pSpeed = player.getComponent<TransformComponent>().speed;

    for(auto t : tiles)
    {
        //when we go right, we scroll the tiles left
        t->getComponent<TileComponent>().destRect.x +=  -(pVel.x * pSpeed);
        t->getComponent<TileComponent>().destRect.y += -(pVel.y * pSpeed);
    } */

    //take away half of the screen to leave player in middle
    //800
    camera.x = static_cast<int>(player.getComponent<TransformComponent>().position.x - 400);
    //640
    camera.y = static_cast<int>(player.getComponent<TransformComponent>().position.y - 320);

    //check bounds
    if(camera.x < 0)
        camera.x = 0;
    if(camera.y < 0)
        camera.y = 0;
    if(camera.x > camera.w)
        camera.x = camera.w;
    if(camera.y > camera.h)
        camera.y = camera.h;

}

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

    for(auto& c : colliders){
        c->draw();
    }

    for(auto& p : players){
        p->draw();
    }

    for(auto& p : projectiles){
        p->draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}