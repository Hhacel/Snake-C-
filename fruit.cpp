#include "fruit.h"

Fruit::Fruit(int w, int h, int block_size_)
{
    width = w;
    height = h;
    block_size = block_size_;
    fruit_position = draw_position();
}

Fruit::~Fruit()
{
    //dtor
}

sf::Vector2f Fruit::draw_position()
{
    int x;
    int y;
    x = (rd() % (int(width)/block_size))*block_size;
    y = (rd() % (int(height)/block_size))*block_size;
    fruit_position = sf::Vector2f (x,y);
    return fruit_position;
}
