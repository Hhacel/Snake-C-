#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Snake
{
    public:
        Snake(int side_length, sf::RenderWindow* render_window,
            int head_x, int head_y, int snake_length);
        ~Snake();
        void move(std::string direction);
        void draw();
        std::string LEFT;
        std::string RIGHT;
        std::string UP;
        std::string DOWN;
        int side_length;
        sf::RenderWindow* window;

    protected:

    private:
        std::vector<sf::RectangleShape> _parts;
        void _move_left(int width);
        void _move_right(int width);
        void _move_up(int height);
        void _move_down(int height);
        void _move_tail();
};

#endif // SNAKE_H
