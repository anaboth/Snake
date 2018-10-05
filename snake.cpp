#include "snake.h"

int Snake::update() {

    for(int i = body.size() - 1; i > 0; --i)
        body[i].setPosition(body[i - 1].getPosition());

    body[0].move(sf::Vector2f(speedX, speedY));

    sf::Vector2f pos = body[0].getPosition();

    if(pos.x > 400) body[0].setPosition(0, pos.y);
    if(pos.x < 0)   body[0].setPosition(400, pos.y);
    if(pos.y > 400) body[0].setPosition(pos.x, 0);
    if(pos.y < 0)   body[0].setPosition(pos.x, 400);

    for(int i = body.size() - 1; i > 0; --i)
        if(body[i].getPosition() == body[0].getPosition())
            return 1;

    return 0;
}

int Snake::draw(sf::RenderWindow& window){

    for(auto& i : body){
        window.draw(i);
    }

    return 0;
}

int Snake::grow(){
    sf::RectangleShape temp(sf::Vector2f(w, h));
    temp.setPosition(body[0].getPosition());
    temp.setFillColor(sf::Color::Black);
    body.push_back(temp);
    return 0;
}

int Snake::setSpeed(int x, int y){
    if (speedX != 0 && x != 0) return -1;
    if (speedY != 0 && y != 0) return -1;
    speedX = x;
    speedY = y;

    return 0;
}

sf::RectangleShape Snake::getHead(){
    return body[0];
}