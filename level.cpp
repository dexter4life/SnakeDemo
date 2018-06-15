#include "level.h"

#include <vector>
using std::vector;
#include <algorithm>
#include <string>
using std::string;

/****************************************************************
 [  1  ]   ▒
 [  2  ]   ▓
 [  3  ]   │
 [  4  ]   ┤
 [  5  ]   ╡
 [  6  ]   ╢
 [  7  ]   ╖
 [  8  ]   ╕
 [  9  ]   ╣
 [  10  ]   ║
 [  11  ]   ╗
 [  12  ]   ╝
 [  13  ]   ╜
 [  14  ]   ╛
 [  15  ]   ┐
 [  16  ]   └
 [  17  ]   ┴
 [  18  ]   ┬
 [  19  ]   ├
 [  20  ]   ─
 [  21  ]   ┼
 [  22  ]   ╞
 [  23  ]   ╟
 [  24  ]   ╚
 [  25  ]   ╔
 [  26  ]   ╩
 [  27  ]   ╦
 [  28  ]   ╠
 [  29  ]   ═
 [  30  ]   ╬
 [  31  ]   ╧
 [  32  ]   ╨
 [  33  ]   ╤
 [  34  ]   ╥
 [  35  ]   ╙
 [  36  ]   ╘
 [  37  ]   ╒
 [  38  ]   ╓
 [  39  ]   ╫
 [  40  ]   ╪
 [  41  ]   ┘
 [  42  ]   ┌
 [  43  ]   █
 [  44  ]   ▄
 [  45  ]   ▌
 ****************************************************************/
Level::Level(string &str ) : Screen(str)
{
    a = xmlparser.getLevelAttribute();

    for( int i = 1, j = 177; j <= 221; j++, i++ )
    {
        mapChar(i, char(j));
    }
}

void Level::render()
{
    typedef vector<Attribute>::iterator iter;

    std::for_each(a.begin(), a.end(), [this]( Attribute &i )-> void
    {
        Attribute *it = &i;

        if(  it->ycount == 1 && it->xcount > 1 )
        {
            for( int x = it->x, i = 0; i < it->xcount; i++)
            draw(it->y, x+i, getChar(it->id));
        }
        else if ( it->ycount > 1 && it->ycount < h)
        {
            for( int y = it->y, i = 0; i < it->ycount; i++)
            draw(y+i, it->x, getChar(it->id));
        }
        else
            draw(it->y, it->x, getChar(it->id));

    } );

    Screen::render();
}
