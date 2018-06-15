#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <Windows.h>

class EventHandler
{
public:
    EventHandler();

    inline bool up() const;
    inline bool left() const;
    inline bool right() const;
    inline bool down() const;

    bool EventLister();
private:
     HANDLE hIn;
     INPUT_RECORD inputRec[8];
     DWORD eventCount;

     bool u, d, l, r;
};

#endif // EVENTHANDLER_H
