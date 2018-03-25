#include <stdio.h>
#include <string.h>
#include <ncurses.h>

void print_in_middle(WINDOW* win, int y, int x, int w, int h, char* string);

int main(int argc, char** argv)
{
	initscr();

	if(!has_colors())
	{
		endwin();
		printf("Your terminal does not support color\n");
		return 1;
	}
	
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK); 
	
	attron(COLOR_PAIR(1));

	print_in_middle(stdscr, LINES / 2, COLS / 2, 0, 0, "Viola !!! In color ...");

	attroff(COLOR_PAIR(1));

	getch();

	endwin();

	return 0;
}

void print_in_middle(WINDOW* win, int y, int x, int w, int h, char* string)
{
	int length, x_, y_;
	float temp; 
	
	if (win == NULL)
		win = stdscr;
	
	getyx(win, y_, x_);
	
	if ( x != 0 ) 
		x_ = x; 
	if ( y != 0 ) 
		y_ = y; 
	if ( w == 0 )
		w = 80;

	length = strlen(string);
	temp = (w - length) / 2;
	x_ = x + (int)temp;
	mvprintw(win, y, x, "%s", string);
	refresh();
}
