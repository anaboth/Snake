#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "utils.h"

class Snake {

private:
    std::vector<point> body;
    int speedY = 0;
    int speedX = 0;
    int w = 10;
    int h = 10;
    SDL_Surface* surface;

public:
    Snake(){
        surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
        body.push_back({0,0});
    }
    
    int setSpeed(int, int);
    int update();
    int draw(SDL_Renderer*);
};