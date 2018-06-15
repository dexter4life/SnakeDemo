#include "eventhandler.h"
#include <windows.h>

EventHandler::EventHandler()
{
    hIn = GetStdHandle( STD_INPUT_HANDLE );

}

bool EventHandler::up() const
{
    return u;
}

bool EventHandler::left() const
{
    return l;
}

bool EventHandler::right() const
{
    return r;
}

bool EventHandler::down() const
{
    return d;
}

bool EventHandler::EventLister()
{

    if( !ReadConsoleInputA( hIn,inputRec, 8, &eventCount) )
    {
       for( WORD i = 0; i < eventCount; i++ )
       {
           if( inputRec[ i ].EventType == KEY_EVENT && inputRec[ i ].Event.KeyEvent.bKeyDown )
           {
                switch( inputRec[ i ].Event.KeyEvent.wVirtualKeyCode )
                {
                case VK_UP:
                    u = true;
                break;
                case VK_DOWN:
                    d = true;
                break;
                case VK_LEFT:
                    l = true;
                    break;
                case VK_RIGHT:
                    r = true;
                    break;
                default:
                    u = false;
                    d = false;
                    l = false;
                    r = false;
                }
                return true;
           }
           else
               return false;
       }

    }
    return false;
}
