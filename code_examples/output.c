#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main()
{
	initscr(); 
	
	printw("I'm here in the shadows\n");
	addch('a' | A_BOLD | A_UNDERLINE);

	move(5, 5); 
	addch('b' | A_UNDERLINE);

	mvaddch(10, 10, 'c'); 

	move(2, 10);
	printw("I am here in the shadows\n");
		
	mvprintw(1, 15, "For Artanis!");
	addstr("Cold void");
	
	attron(A_BLINK);
	mvprintw(2, 4, "666");

	refresh(); 

	move(30, 0);

	attron(A_BLINK);
	int i; 
	for(i = 0; i < 10; ++i)
	{
		printw("666");
		move(30, i+3);
	}	
	
	attroff(A_BLINK); 
	printw("777");
		
	getch(); 
	endwin();
	return 0; 
}
