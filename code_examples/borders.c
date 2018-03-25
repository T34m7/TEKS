#include <ncurses.h>

typedef struct _win_border_struct 
{
	chtype ls, rs, ts, bs, 	
		   tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct
{
	int x, y; 
	int w, h; 
	WIN_BORDER border; 
}WIN;

void init_win_params(WIN* p_win); 
void print_win_params(WIN* p_win);
void create_box(WIN* win, bool flag);

int main()
{
	WIN win; 
	int ch; 
		
	initscr();
	start_color();
	cbreak();

	keypad(stdscr, TRUE);
	noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	
	init_win_params(&win);
	print_win_params(&win);

	attron(COLOR_PAIR(1)); 
	printw("press f1 to exit");
	refresh(); 
	attroff(COLOR_PAIR(1));
	
	create_box(&win, TRUE);
	while ( (ch = getch()) != KEY_F(1))
	{
		switch(ch)
		{
			case KEY_LEFT: 
					create_box(&win, FALSE); 
					--win.x;
					create_box(&win, TRUE); 
					break; 
			case KEY_RIGHT: 
					create_box(&win, FALSE); 
					++win.x;
					create_box(&win, TRUE); 
					break; 
			case KEY_UP: 
					create_box(&win, FALSE); 
					--win.y;
					create_box(&win, TRUE); 
					break; 
			case KEY_DOWN: 
					create_box(&win, FALSE); 
					++win.y;
					create_box(&win, TRUE); 
					break; 
		}	
	}
	
	endwin(); 
	return 0; 
}

void init_win_params(WIN* p_win)
{
	p_win->h = 3; 
	p_win->w = 10;
	p_win->y = (LINES - p_win->h) / 2;
	p_win->x = (COLS  - p_win->w) / 2; 


	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';
}

void print_win_params(WIN* p_win)
{
#ifdef _DEBUG
		mvprintw(25, 0 , "%d %d %d %d", p_win->x, p_win->y, p_win->w, p_win->h);
		refresh();
#endif	
}

void create_box(WIN* p_win, bool flag)
{
	int i, j; 
	int x, y, w, h; 
	
	x = p_win->x;
	y = p_win->y;
	w = p_win->w;
	h = p_win->h;

	if(flag)
	{
		mvaddch(y, x, p_win->border.tl);
		mvaddch(y, x + w, p_win->border.tr);
		mvaddch(y + h, x, p_win->border.bl);
		mvaddch(y + h, x + w, p_win->border.br);
		mvhline(y, x + 1, p_win->border.ts, w - 1);
		mvhline(y + h, x + 1, p_win->border.bs, w - 1);
		mvvline(y + 1, x, p_win->border.ls, h - 1);
		mvvline(y + 1, x + w, p_win->border.rs, h - 1);
	}
	else 
		for(j = y; j <= y + h; ++j)
			for(i = x; i <= x + w; ++i)
				mvaddch(j, i, ' ');	
				
	refresh(); 
}




















