#ifndef GAMES_HPP
#define GAMES_HPP
#include<SDL2/SDL.h>
#include<vector>
#include<iostream>
#include "SDL2_image-2.6.2/SDL_image.h"

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include<SDL2/SDL_opengles2.h>
#else
#include<SDL2/SDL_opengl.h>
#endif

class ColliderComponent;

class Game{

private:
    bool isRunning;
    SDL_Window* window;

    public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    bool running(){return isRunning;}
    void render();
    void clean();

    static void AddTile(int id, int x, int y);
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
};

#endif/*GAMES_HPP*/