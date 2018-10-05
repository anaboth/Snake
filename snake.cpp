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
    temp.setPosition(sf::Vector2f(0, 0));
    temp.setFillColor(sf::Color::Black);
    body.push_back(temp);
    return 0;
}

int Snake::setSpeed(int x, int y){
    speedX = x;
    speedY = y;

    return 0;
}