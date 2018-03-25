#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main()
{
	int ch, num; 
	char* str; 

	initscr();

	printw("ENTER CHARACTER: "); 
	ch = getch();
	printw("\n");
	
	printw("ENTER FORMATTED NUM: ");
	scanw("%d", &num);
	printw("\n"); 
	
	printw("ENTER STRING: "); 
	getstr(str); 	

	endwin();
	return 0; 	
}
