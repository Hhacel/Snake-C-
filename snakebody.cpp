#include "snakebody.h"

SnakeBody::SnakeBody(int length, int block_size_value, sf::RenderWindow* window)
{
    block_size = block_size_value;
    render_window = window;
    width = render_window->getSize().x;
    height = render_window->getSize().y;
    points = 0;
    for(int i=0; i<length; i++)
    {
        body.push_front(sf::Vector2f(i * block_size, 0));
    }
    set_vectors();
    fruit = new Fruit(width, height, block_size);
}

SnakeBody::~SnakeBody()
{
    //dtor
}

bool SnakeBody::game_over()
{
    std::list<sf::Vector2f>::iterator it = body.begin();
    it++;
    for (it ; it!= body.end(); it++)
    {
        if (*it == *body.begin())
            return true;
    }
    return false;
}
void SnakeBody::draw()
{
    for (std::list<sf::Vector2f>::iterator it = body.begin(); it!= body.end(); it++ )
    {
        sf::RectangleShape rectangle(sf::Vector2f(block_size, block_size));
        rectangle.setPosition(*it);
        render_window->draw(rectangle);
    }
    sf::RectangleShape rectangle(sf::Vector2f(block_size, block_size));
    rectangle.setPosition(fruit->fruit_position);
    render_window->draw(rectangle);

}


void SnakeBody::move(std::string direction)
{
    make_difference(direction);
    body.push_front(body.front() + difference);
    if (fruit->fruit_position != body.front())
    {
    body.pop_back();
    }
    else
    {
        points++;
        make_fruit();
    }
    validate_head();

}

void SnakeBody::validate_head()
{
    float x = body.front().x;
    float y = body.front().y;

    if (x < 0)
        x += width;
    if (x >= width)
        x -= width;
    if (y < 0)
        y += height;
    if (y >= height)
        y -= height;

    body.front().x = x;
    body.front().y = y;
}

void SnakeBody::make_fruit()
{
    do
    {
        fruit->draw_position();
    }
    while (has_collision());
}

bool SnakeBody::has_collision()
{
    for (std::list<sf::Vector2f>::iterator it = body.begin(); it!=body.end(); it++)
    {
        if(*it == fruit->fruit_position)
            return true;
    }
    return false;
}

void SnakeBody::show_points()
{
    sf::Font font;
    str = std::to_string(points);
if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
    points_board.setFont(font);
    points_board.setCharacterSize(36);
    points_board.setString(str);
    points_board.setFillColor(sf::Color::White);
    points_board.setPosition(0,22);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setString("Points:");
    render_window->draw(points_board);
    render_window->draw(text);
}

void SnakeBody::game_over_picture()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
    points_board.setFont(font);
    points_board.setPosition(width/2,height/2);
    points_board.setCharacterSize(height/10);
    text.setFont(font);
    text.setCharacterSize(height/6);
    text.setString("Game Over");
    text.setPosition(width*3/16,height*3/10);
    render_window->draw(points_board);
    render_window->draw(text);
}


