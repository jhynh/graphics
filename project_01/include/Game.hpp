#ifndef GAMES_HPP
#define GAMES_HPP
#include<SDL2/SDL.h>
#include "SDL_image.h"
#include<iostream>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include<SDL2/SDL_opengles2.h>
#else
#include<SDL2/SDL_opengl.h>
#endif

class Game{

private:
    int count;
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

    static SDL_Renderer* renderer;
};

#endif/*GAMES_HPP*/