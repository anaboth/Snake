#pragma once

#include <vector>
#include <iostream>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>

class Snake {

private:
    std::vector<sf::RectangleShape> body;
    int speedY = 0;
    int speedX = 0;
    int w = 10;
    int h = 10;

public:
    Snake(){
        sf::RectangleShape temp(sf::Vector2f(w,h));
        temp.setPosition(sf::Vector2f(0, 0));
        temp.setFillColor(sf::Color::Black);
        body.push_back(temp);
    }

    ~Snake(){}
    
    int grow();
    int setSpeed(int, int);
    int update();
    int draw(sf::RenderWindow&);
};