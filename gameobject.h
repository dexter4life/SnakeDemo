#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Windows.h>
#include <map>
using std::map;

class GameObject
{
public:
    GameObject();

    virtual ~GameObject();

    virtual void render() = 0;

    void mapChar(int i, char c);
    char getChar( int i );

protected:
     map< int, char > value;
};

#endif // GAMEOBJECT_H
