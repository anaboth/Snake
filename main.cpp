#include <iostream>
#include <SDL2/SDL.h>

void err(int status, const char* text){
    fscanf(stderr, "%s", text);
    exit(status);
}

int main(int argc, char const *argv[]){

    SDL_Window* window;
    SDL_Renderer* renderer;
    const int w = 400;
    const int h = 400;

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
    if (!window) err(-1, SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) err(-1, SDL_GetError());

    SDL_Event e;
    
    while(true){
        // Handle Inputs
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT)
            break;

        // Graphical things
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0x0, 0xff, 0xff, 0xff);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    return 0;
}
