    #include "screen.h"
#include <iostream>
using std::cout;

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
       memset(board[i], ' ', sizeof(char) * w);
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
    COORD pos = { 3, 0 };
    DWORD written;
    WORD br = BACKGROUND_BLUE | FOREGROUND_RED>>1;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for( int i = 0; i < h; i++ )
    {
        FillConsoleOutputAttribute(hOut, br, w, pos, &written );
        WriteConsoleOutputCharacterA(hOut,board[i], w, pos, &written );
         pos.Y++;
    }
}

bool Screen::isWall( int y, int x ) const
{
    return board[y][x] == FLOOR;
}

int Screen::getHeight() const
{
    return h;
}

int Screen::getWidth() const
{
    return w;
}
