#include "snake.h"

Snake::Snake()
{
    pos.X = 2;
    pos.Y = 2;
}

void Snake::moveUp()
{
    if(isWall(pos.Y, pos.X))
    {
       draw(--pos.Y, pos.X, 'o');
    }
}

void Snake::moveDown()
{
    if( isWall(pos.Y, pos.X) )
    {
        draw(++pos.Y, pos.X, 'o');
    }
}

void Snake::moveLeft()
{
    if( isWall(pos.Y, pos.X) )
    {
        draw(pos.Y, --pos.X, 'o');
    }
}

void Snake::moveRight()
{
    if( isWall(pos.Y, pos.X ))
    {
        draw(pos.Y, ++pos.X, 'o');
    }
}
