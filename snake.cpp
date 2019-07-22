#include "snake.h"

Snake::Snake(int side, sf::RenderWindow* render_window, int head_x, int head_y, int snake_length)
{
    LEFT = "LEFT";
    RIGHT = "RIGHT";
    UP = "UP";
    DOWN = "DOWN";
    side_length = side;
    window = render_window;

    for(int i=0; i<snake_length; i++)
    {
        _parts.push_back(sf::RectangleShape(sf::Vector2f(side_length, side_length)));
        if(i > 1)
            _parts[i].setPosition(_parts[i-1].getPosition().x - side_length, head_y);
        else
            _parts[i].setPosition(head_x, head_y);
    }
}

Snake::~Snake()
{
    //dtor
}


void Snake::move(std::string direction)
{
    sf::Vector2u windows_size = window->getSize();
    if(direction == LEFT)
        _move_left(windows_size.x);
    else if(direction == RIGHT)
        _move_right(windows_size.x);
    else if(direction == UP)
        _move_up(windows_size.y);
    else if(direction == DOWN)
        _move_down(windows_size.y);
}

void Snake::draw()
{
    for(int i=0; i<_parts.size(); i++)
        window->draw(_parts[i]);
}

void Snake::_move_left(int width)
{
    sf::Vector2f head_old_position = _parts[0].getPosition();
    int head_new_x = head_old_position.x - side_length;
    if(head_new_x < 0)
        head_new_x += width;

    _move_tail();
    _parts[0].setPosition(head_new_x, head_old_position.y);
}

void Snake::_move_right(int width)
{
    sf::Vector2f head_old_position = _parts[0].getPosition();
    int head_new_x = head_old_position.x + side_length;
    if(head_new_x >= width)
        head_new_x -= width;

    _move_tail();
    _parts[0].setPosition(head_new_x, head_old_position.y);
}

void Snake::_move_up(int height)
{
    sf::Vector2f head_old_position = _parts[0].getPosition();
    int head_new_y = head_old_position.y - side_length;
    if(head_new_y < 0)
        head_new_y += height;
    _move_tail();
    _parts[0].setPosition(head_old_position.x, head_new_y);
}

void Snake::_move_down(int height)
{
    sf::Vector2f head_old_position = _parts[0].getPosition();
    int head_new_y = head_old_position.y + side_length;
    if(head_new_y >= height)
        head_new_y -= height;
    _move_tail();
    _parts[0].setPosition(head_old_position.x, head_new_y);
}

void Snake::_move_tail()
{
    std::vector<sf::Vector2f> previous_positions;
    for(int i=0; i<_parts.size(); i++)
        previous_positions.push_back(_parts[i].getPosition());

    for(int i=1; i<_parts.size(); i++)
        _parts[i].setPosition(previous_positions[i-1]);
    previous_positions.clear();
    for(int i=0; i<_parts.size(); i++)
        std::cout << _parts[i].getPosition().x << ' ';
    std::cout << std::endl;
}
