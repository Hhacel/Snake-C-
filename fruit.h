#ifndef FRUIT_H
#define FRUIT_H
#include <stdlib.h>
#include <random>
#include <SFML/Graphics.hpp>


class Fruit
{
    public:
        Fruit(int w, int h, int block_size_);
        virtual ~Fruit();
        sf::Vector2f fruit_position;
        sf::Vector2f draw_position();
    protected:

    private:
        std::random_device rd;
        int width;
        int height;
        int block_size;

};

#endif // FRUIT_H
