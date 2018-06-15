    #include "screen.h"
#include <iostream>
using std::cout;


char **Screen::board;

Screen::Screen()
{

}

Screen::Screen( std::string filepath ) : xmlparser(filepath)
{
    h = xmlparser.getHeight();
    w = xmlparser.getWidth();
    level = xmlparser.getLevelType();

    board = new char*[ h ];

    for( int i = 0; i < h; i++ )
        board[i] = new char[w];

    reset();
}
Screen::~Screen()
{
    for( int i = 0; i < h; i++ )
        delete [] board[ i ];
}

void Screen::reset()
{
    for( int i = 0; i < h; i++ )
    {
       memset(board[i], FLOOR, sizeof(char) * w);
    }
}

void Screen::draw( const COORD &position, const char item )
{
    draw(position.Y, position.X, item);
}

void Screen::draw( int Y, int X, const char item )
{
       if( ( Y >= 0 && Y < h ) && ( X >= 0 && X < w))
            board[Y][X] = item;
}

void Screen::render()
{
    
}

bool Screen::isWall( int y, int x ) const
{
    return !(board[y][x] == FLOOR);
}

int Screen::getHeight() const
{
    return h;
}

int Screen::getWidth() const
{
    return w;
}
