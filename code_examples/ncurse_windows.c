#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

WINDOW* create_newwin(int h, int w, int y, int x);
void destroy_win(WINDOW* local_win);

int main(int argc, char** argv)
{
	initscr(); 
	
	WINDOW* my_win;

	int w, h, y, x;
	int ch;

	initscr; 
	cbreak();
	keypad(stdscr, TRUE);

	h = 3; 
	w = 10; 

	y = (LINES - h) / 2;
	x = (COLS - w) / 2; 

	printw("press f1 to exit");
	refresh(); 

	my_win = create_newwin(h, w, y, x);

	while ( (ch = getch()) != KEY_F(1) )
	{
		switch(ch)
		{
			case KEY_LEFT:
					destroy_win(my_win);
					my_win = create_newwin(h, w, y , --x);
					break; 
			case KEY_RIGHT: 
					destroy_win(my_win); 
					my_win = create_newwin(h, w, y, ++x);
					break;
			case KEY_UP: 
					destroy_win(my_win);
					my_win = create_newwin(h, w, --y, x); 
					break; 
			case KEY_DOWN: 
					destroy_win(my_win);
					my_win = create_newwin(h, w, ++y, x);	
					break;
			default: 		
					break;
		}
	}
	
	endwin();
	return 0; 
}

WINDOW* create_newwin(int h, int w, int y, int x)
{
	WINDOW* local_win;
	
	local_win = newwin(h, w, y, x);
	box(local_win, 0, 0); 
	
	wrefresh(local_win);
	
	return local_win;
}

void destroy_win(WINDOW* local_win)
{	

	wborder(local_win, ' ', 
					   ' ', 
					   ' ',' ',
					   ' ',' ',
                       ' ',' ');
	wrefresh(local_win);
	delwin(local_win);

	//wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	
//	  +------------+
//    |            |
//    |            |
//    |            |
//    |            |
//    |            |
//    |            |
//    +------------+

}
