#include <ncurses.h>

int main(int argc, char** argv)
{
	initscr(); // start curses mode 
	printw("Hello World!"); // print function
	refresh(); 
	getch();
	endwin();
	return 0; 
}
