#ifndef SNAKE_H
#define SNAKE_H

#include "screen.h"

class Snake : public Screen
{
public:
    Snake();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

private:
    COORD pos;
};

#endif // SNAKE_H
