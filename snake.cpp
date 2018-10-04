#include "snake.h"

int Snake::update() {

    for(int i = body.size() - 1; i > 0; --i){
        body[i]->x = body[i - 1]->x;
        body[i]->y = body[i - 1]->y;
    }

    body[0]->x += speedX;
    body[0]->y += speedY;

    if(body[0]->x > 400) body[0]->x = 0;
    if(body[0]->x < 0) body[0]->x = 400;
    if(body[0]->y > 400) body[0]->y = 0;
    if(body[0]->y < 0) body[0]->y = 400;

    return 0;
}

int Snake::draw(SDL_Renderer* renderer){

    for(auto& i : body){
        SDL_FillRect(surface, i, SDL_MapRGB(surface->format, 0, 0, 0));
        SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, surface), NULL, i);
    }

    return 0;
}

int Snake::grow(){
    body.push_back(new SDL_Rect);
    body[body.size() - 1]->w = h;
    body[body.size() - 1]->h = h;
    return 0;
}

int Snake::setSpeed(int x, int y){
    speedX = x;
    speedY = y;

    return 0;
}