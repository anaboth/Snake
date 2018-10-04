#pragma once

#include <cstdio>
#include <cstdlib>
#include <SDL2/SDL.h>

struct point {
    int x;
    int y;
    SDL_Rect* r;
};

void err(int, const char*);