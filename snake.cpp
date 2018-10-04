#include "snake.h"

int Snake::update() {

    std::cout << body.size();

    for(int i = body.size() - 1; i > 0; --i){
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }

    body[0].x += speedX;
    body[0].y += speedY;

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

int Snake::grow(){
    point p = {0, 0};
    body.push_back(p);
}

int Snake::setSpeed(int x, int y){
    speedX = x;
    speedY = y;
}