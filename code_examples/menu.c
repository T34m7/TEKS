#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int main(int argc, char** argv)
{	
	unsigned int menu_len = 5; 
	char** menu = (char**)malloc(menu_len * sizeof(char*)); 

	int i; 
	for(i = 0; i < menu_len; ++i)
		menu[i] = (char*)malloc(5);

	strcpy(menu[0], "menu1"); 
	strcpy(menu[1], "menu2");
	strcpy(menu[2], "menu3");
	strcpy(menu[3], "menu4");
	strcpy(menu[4], "menu5");

	initscr();
	noecho(); 
	unsigned int choose_x = 7; 
	unsigned int choose_y = 0;
	

	for(i = 0; i < menu_len; ++i)
	{
		printw(menu[i]);
		printw("\n"); 
	}

	mvaddch(choose_y, choose_x, 'X'); 
 
	refresh();

	int quit = 0; 
	int ch; 
	while(!quit)
	{
		ch = getch();
		switch(ch)
		{
			case 'w': 
					if (choose_y == 0)
						break; 
					else
					{
						mvaddch(choose_y, choose_x, ' ');  
						--choose_y; 
						mvaddch(choose_y, choose_x, 'X');  
					}
					break;
			case 's': 
					if (choose_y == menu_len - 1)
						break; 
					else
					{
						mvaddch(choose_y, choose_x, ' ');  
						++choose_y; 
						mvaddch(choose_y, choose_x, 'X');  
					}
					break;
			case '.':
					quit = 1; 
					break;
			default: 
					break;
		}
		refresh(); 
	}
	
	endwin();

	return 0; 
}
