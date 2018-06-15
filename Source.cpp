#include <curses.h>
#include <list>
#include <algorithm>
#include <string>
#include "xmlparser.h"

using std::list;
using std::string;

struct Point
{
	int X, Y;
};

class Snake
{
public:
	Snake(int x, int y) : size(4)
	{
		init_p.X = x;
		init_p.Y = y;
		push_front(init_p);
	}
	void pop_front();
	void pop_back();
	void push_front(Point p);
	void push_back(Point p);
	void render();
	void move(int, int);
private:
	int size;
	Point init_p;
	list< Point > snake;
};

void Snake::push_front(Point p)
{
	snake.push_front(p);
}

void Snake::push_back(Point p)
{
	snake.push_back(p);
}

void Snake::pop_front()
{
	snake.pop_front();
}

void Snake::pop_back()
{
	snake.pop_back();
}

void Snake::render()
{
	std::for_each(snake.begin(), snake.end(),
	[](Point &p)->void {
		mvaddch(p.Y, p.X, 'o');
	});
}

void Snake::move(int x, int y)
{
	Point tmp = init_p;
	tmp.X += x;
	tmp.Y += y;
	init_p = tmp;
	snake.push_back(init_p);
	mvaddch(snake.front().Y, snake.front().X, ' ');
	pop_front();
}

int main()
{
	
	XmlParser xmlParser(string("level.xml"));

	initscr();
	clear();
	curs_set(0);
	cbreak();
	noecho();
	box(stdscr, 0, 0);
	

	Snake snake(10, 10);

	Point p[20];
	
	for (int i = 0, j=11; i < 20; i++)
	{
		p[i].X = 10;
		p[i].Y = j++;
		snake.push_back(p[i]);
	}

	
	if (has_colors())
		start_color();

	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	bkgd( ' ' | COLOR_PAIR(1));
	keypad(stdscr, true);

	int ch = 0;

	while ( ch != 'q')
	{
		nodelay(stdscr, true);
		ch = getch();
		switch (ch)
		{
		case KEY_F(1):
			ch = 'q';
			break;
		case KEY_RIGHT:
			snake.move(1, 0);
			break;
		case KEY_DOWN:
			snake.move(0, 1);
			break;
		case KEY_LEFT:
			snake.move(-1, 0);
			break;
		case KEY_UP:
			snake.move(0, -1);
			break;
		default:
			break;
		}
		snake.render();
		refresh();
		napms(30);
		
	}

	endwin();
	return 0;
}