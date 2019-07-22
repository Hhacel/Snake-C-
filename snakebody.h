#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <cstdio>
#include "movement.h"
#include "fruit.h"

class SnakeBody : public Movement
{
    public:
        std::list <sf::Vector2f> body;
        int height;
        int width;
        int points;

        sf::RenderWindow* render_window;
        void draw();
        SnakeBody(int length, int block_size_value, sf::RenderWindow* window);
        void move(std::string direction);
        void validate_head();
        void make_fruit();
        bool game_over();
        void show_points();
        void game_over_picture();

        Fruit* fruit;
        virtual ~SnakeBody();


    protected:

    private:
        bool has_collision();

        std::string str;

        sf::Text points_board;
        sf::Text text;
};

#endif // SNAKEBODY_H
