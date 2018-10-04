#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "utils.h"
#include <iostream>
#include <cstdio>

class Snake {

private:
    std::vector<SDL_Rect*> body;
    int speedY = 0;
    int speedX = 0;
    int w = 10;
    int h = 10;
    SDL_Surface* surface;

public:
    Snake(){
        surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
        body.push_back(new SDL_Rect);
        body[0]->w = w;
        body[0]->h = h;
        body[0]->x = 0;
        body[0]->y = 0;
    }

    ~Snake(){
        for(auto& i : body)
            delete i;
    }
    
    int grow();
    int setSpeed(int, int);
    int update();
    int draw(SDL_Renderer*);
};