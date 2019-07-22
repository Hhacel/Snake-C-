#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <SFML/Graphics.hpp>
#include <string>


class Movement
{
    public:
        std::string UP = "UP";
        std::string DOWN = "DOWN";
        std::string RIGHT = "RIGHT";
        std::string LEFT = "LEFT";

        sf::Vector2f vector_right;
        sf::Vector2f vector_left;
        sf::Vector2f vector_up;
        sf::Vector2f vector_down;

        sf::Vector2f difference;

        void set_vectors();
        void make_difference(std::string direction);

        Movement();
        virtual ~Movement();
    protected:
        int block_size;

    private:
};

#endif // MOVEMENT_H
