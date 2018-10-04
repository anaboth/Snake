#include <iostream>
#include <SDL2/SDL.h>
#include "snake.h"
#include "utils.h"

int main(int argc, char const** argv){

    SDL_Window* window;
    SDL_Renderer* renderer;
    const int w = 400;
    const int h = 400;
    Snake snake;

    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
    if (!window) err(-1, SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) err(-1, SDL_GetError());

    SDL_Event e;

    int currTime = SDL_GetTicks();
    int prevTime = currTime;
    int delta;


    while(true){
        prevTime = currTime;
        currTime = SDL_GetTicks();
        delta = currTime - prevTime;

        // Handle Inputs

        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT)
            break;
        if(e.type == SDL_KEYDOWN){
            if(e.key.keysym.sym == SDLK_w)
                snake.setSpeed(0, -1);
            if(e.key.keysym.sym == SDLK_a)
                snake.setSpeed(-1, 0);
            if(e.key.keysym.sym == SDLK_s)
                snake.setSpeed(0, 1);
            if(e.key.keysym.sym == SDLK_d)
                snake.setSpeed(1, 0);
            if(e.key.keysym.sym == SDLK_q)
                break;
            if(e.key.keysym.sym == SDLK_SPACE)
                snake.grow();
        }

        // Update stuff
        snake.update();

        // Graphical things
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        snake.draw(renderer);
        SDL_RenderPresent(renderer);

        // if (currTime - prevTime < 1000 / 5){
        //     SDL_Delay(1000 / 5 - SDL_GetTicks() + prevTime);
        // }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
