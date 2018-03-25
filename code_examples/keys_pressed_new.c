#include <ncurses.h>

int main()
{
	int ch;
	int quit = 0; 

	// initialization 
	initscr(); // init ncurses 
	raw(); // some characters send signals to terminal
	noecho(); // don't echo characters which user input
	keypad(stdscr, TRUE); // allow type F1 - F12 characters 

	printw("Start typing characters!\n"); 

	while(!quit)
	{
		ch = getch();
		if (ch == '.')
			quit = 1;  
		printw("%c", ch);
		refresh();
	}

	endwin(); 
	return 0;
}
