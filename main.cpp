
#include "screen.h"
#include "level.h"
#include "snake.h"
#include "eventhandler.h"

using std::string;

int main()
{
    Level level(string("level.xml"));
    Snake snake;
    EventHandler eventHandler;

    while(true)
    {
        level.render();

        if( eventHandler.EventLister())
        {
            if( eventHandler.down() )
                snake.moveDown();
        }
    }
}
