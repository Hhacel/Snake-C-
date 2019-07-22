#include "movement.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Movement::Movement()
{
    //snake_body = snake_body_pointer;

}

Movement::~Movement()
{
    //dtor
}

void Movement::set_vectors()
{
    vector_up = sf::Vector2f (0, -block_size);
    vector_down = sf::Vector2f (0, block_size);
    vector_left = sf::Vector2f (-block_size, 0);
    vector_right = sf::Vector2f (block_size, 0);
}

void Movement::make_difference(std::string direction)
{
    if (direction == UP)
        difference = vector_up;
    else if (direction == DOWN)
        difference = vector_down;
    else if (direction == LEFT)
        difference = vector_left;
    else if (direction == RIGHT)
        difference = vector_right;
}
