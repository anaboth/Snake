#include <iostream>
#include "snake.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool collided(sf::Vector2f, sf::Vector2f);

int main(int argc, char const** argv){

    const int w = 400;
    const int h = 400;
    int frame = 10;
    Snake snake;
    int score = 0;

    std::srand(0);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::Font font;
    font.loadFromFile("BebasNeue-Regular.ttf");

    sf::Text scoreText("Score: " + std::to_string(score), font);
    scoreText.setCharacterSize(18);
    scoreText.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game", sf::Style::Default, settings);

    sf::RectangleShape apple(sf::Vector2f(10, 10));

    apple.setPosition(sf::Vector2f(((int)(std::rand() % 400) % 10) * 10, ((int)(std::rand() % 400) % 10) * 10));
    apple.setFillColor(sf::Color::Red);

    window.setFramerateLimit(frame);

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
                if(e.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        // Update stuff
        if(snake.update())
            window.close();
        if(collided(snake.getHead().getPosition(), apple.getPosition())){
            snake.grow();
            apple.setPosition(sf::Vector2f(((int)(std::rand() % 400) % 10) * 10, ((int)(std::rand() % 400) % 10) * 10));
            window.setFramerateLimit(++frame);
            score++;
        }
        scoreText.setString("Score: " + std::to_string(score));
        

        // Graphical things
        window.clear(sf::Color::Cyan);
        window.draw(apple);
        snake.draw(window);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}

bool collided(sf::Vector2f v1, sf::Vector2f v2){
    if (v1.x < v2.x + 10 &&
        v1.x + 10 > v2.x &&
        v1.y < v2.y + 10 &&
        v1.y + 10 > v2.y) {
            return true;
    }

    return false;
}