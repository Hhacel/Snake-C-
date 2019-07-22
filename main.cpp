#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include "snakebody.h"

bool is_right(sf::Keyboard::Key code) {
    return code == sf::Keyboard::Right or code == sf::Keyboard::D;
}
bool is_left(sf::Keyboard::Key code) {
    return code == sf::Keyboard::Left or code == sf::Keyboard::A;
}
bool is_up(sf::Keyboard::Key code) {
    return code == sf::Keyboard::Up or code == sf::Keyboard::W;
}
bool is_down(sf::Keyboard::Key code) {
    return code == sf::Keyboard::Down or code == sf::Keyboard::S;
}


int main()
{
    float width = 800;
    float height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Nasz snake");
    int block_size = 50;
    sf::RectangleShape rectangle(sf::Vector2f(block_size, block_size));
    rectangle.setPosition(0,0);

    sf::Clock clock;
    sf::Time time_step = sf::seconds(0.1);

    SnakeBody snake_body(4, block_size, &window);

    std::string direction = snake_body.RIGHT;

    while (window.isOpen())
    {
        if(clock.getElapsedTime() < time_step)
            continue;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if(is_right(event.key.code) and snake_body.difference != snake_body.vector_left) {
                    direction = snake_body.RIGHT;
                }
                else if(is_left(event.key.code) and snake_body.difference != snake_body.vector_right) {
                    direction = snake_body.LEFT;
                }
                else if(is_up(event.key.code) and snake_body.difference != snake_body.vector_down) {
                    direction = snake_body.UP;
                }
                else if(is_down(event.key.code) and snake_body.difference != snake_body.vector_up) {
                    direction = snake_body.DOWN;
                }
            }
        }
        window.clear();
        if (snake_body.game_over()==false)
        {
        snake_body.move(direction);
        snake_body.show_points();
        snake_body.draw();
        }
        else
        snake_body.game_over_picture();

        window.display();
        clock.restart();
    }

    return 0;
}
