#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	// jst data  
	char* str1 = "this string input from program\n\0";
	char* str2 = "input from user:\n\0"; 
	
	unsigned int str1_len = strlen(str1); 
	unsigned int str2_len = strlen(str2); 
	
	// SOME INPUT IN FILE TEST 
	FILE* txt_file = (FILE*)malloc(sizeof(FILE*)); 
	txt_file = fopen("txts/save_to_file.txt", "w");
	fputs(str1, txt_file);
	putc('a', txt_file); 
	fputs("\n", txt_file);

	initscr(); 			  // I
	raw(); 				  // N
	noecho(); 			  // I 
	keypad(stdscr, TRUE); // T

	// []==[:::::::::::::::::> 

	int quit = 0; 
	int ch; 
	
	fputs(str2, txt_file); 

	while(!quit)
	{
		ch = getch(); 
		if (ch == '.')
			quit = 1; 
		printw("%c", ch);	
		putc(ch, txt_file); 					
	}

	endwin(); 
	fclose(txt_file);

	return 0; 	
}
