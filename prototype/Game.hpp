#ifndef GAMES_HPP
#define GAMES_HPP
#include<SDL2/SDL.h>
#include<iostream>
#include"library/SDL2_image-2.6.2/SDL_image.h"
#include<stdio.h>
#include "library/imgui/imgui.h"
#include "library/imgui/backends/imgui_impl_opengl3.h"
#include "library/imgui/backends/imgui_impl_sdl.h"
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include<SDL2/SDL_opengles2.h>
#else
#include<SDL2/SDL_opengl.h>
#endif
class Game{

    private:
    int count;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}
};

class Interface{
    private:

    public:
};

#endif/*GAMES_HPP*/