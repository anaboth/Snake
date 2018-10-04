#include "snake.h"

int Snake::update() {

    for(auto& i : body){
        i.y += speedY;
        i.x += speedX;
    }

    return 1;
}

int Snake::draw(SDL_Renderer* renderer){

    for(auto& i : body){
        SDL_Rect r = { i.x, i.y, h, w };
        SDL_FillRect(surface, &r, SDL_MapRGB(surface->format, 0, 0, 0));
        SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, surface), NULL, &r);
    }

    return 1;
}

int Snake::setSpeed(int x, int y){
    speedX = x;
    speedY = y;
}