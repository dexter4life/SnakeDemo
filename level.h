#ifndef LEVEL_H
#define LEVEL_H

#include "screen.h"
#include <Windows.h>
#include <map>

using std::map;

class Level : public Screen
{
public:
    Level( string &);

    virtual void render();

    vector< Attribute > a;

};

#endif // LEVEL_H
