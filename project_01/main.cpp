#include "Game.hpp"
Game *game = nullptr;

/*
The delay happens because flashingText() was called for every event polled, and the more mouse moves within the window, the more events are fired and polled by the loop. 
*/
int main(int argc, char* argv[]){

    //some vars to cap framerate
    //FPS = 1000/framedelay -> framedelay = 1000/FPS
    const int FPS = 60;                                                                                 //60 is closest to refresh rate of monitor
    const int frameDelay = 1000/FPS;                                                                    //give max time between frames
    
    //large int
    Uint32 frameStart;                                                                                  //# of miliseconds since sdl started
    int frameTime;

    game = new Game();

    game->init("zriels_project", 800, 640, false);

    while(game->running()){
        
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        //in milisecs, give us time for all the events above, now we know how long the frames took, then we need to check if we need to delay
        frameTime = SDL_GetTicks() - frameStart;
        //if we need to delay [FRAME CAP] by the difference
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}