#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int main()
{
	char* file_name; 
	printf("enter filename\n");
	scanf("%s", file_name); 
	strcat(file_name, ".txt");
	
	FILE* txt_file; 
	txt_file = fopen(file_name, "w"); 
	
	initscr(); 
	raw(); 
	noecho(); 
	keypad(stdscr, TRUE); 

	int quit = 0; 
	int ch; 

	while(!quit)
	{
		ch = getch(); 
		if( ch == '.')
			quit = 1;
		printw("%c", ch);
		putc(ch, txt_file);
		refresh(); 
	}

	endwin(); 
	fclose(txt_file);

	return 0; 
} 
