#include <iostream>
#include "snake.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char const** argv){

    const int w = 400;
    const int h = 400;
    Snake snake;

    sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game");

    while(window.isOpen()){

        // Handle Inputs
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
            if(e.type == sf::Event::KeyPressed){
                if(e.key.code == sf::Keyboard::W)
                    snake.setSpeed(0, -10);
                if(e.key.code == sf::Keyboard::A)
                    snake.setSpeed(-10, 0);
                if(e.key.code == sf::Keyboard::S)
                    snake.setSpeed(0, 10);
                if(e.key.code == sf::Keyboard::D)
                    snake.setSpeed(10, 0);
                if(e.key.code == sf::Keyboard::Q)
                    window.close();
                if(e.key.code == sf::Keyboard::Space)
                    snake.grow();
            }
        }

        // Update stuff
        snake.update();

        // Graphical things
        window.clear(sf::Color::Cyan);
        snake.draw(window);
        window.display();
    }

    return 0;
}
