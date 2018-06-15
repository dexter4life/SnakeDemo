#include "gameobject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{

}

void GameObject::mapChar(int i, char c)
{
    value[i] = c;
}

char GameObject::getChar(int i)
{
    return value[i];
}


