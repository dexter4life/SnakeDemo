#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <Windows.h>

#include "xmlparser.h"
#include "gameobject.h"

#define FLOOR ' '

class Screen : public GameObject
{
public:
   Screen();
   Screen(string filepath);
   virtual ~Screen();

   virtual void draw( const COORD &position, const char item );
   virtual void draw( int X, int Y, const char item );

   virtual void reset();

   virtual void render();

   bool isWall(int y, int x) const;

   virtual inline int getHeight() const;
   virtual inline int getWidth() const;

protected:
    XmlParser xmlparser;
    static char **board;
    int h,w, level;
};


#endif // SCREEN_H
