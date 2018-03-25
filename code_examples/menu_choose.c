#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

// (\/) (o)(o) (\/)
// fix TKS_addMenuItem
//
//
//
//
//
//
//

struct MenuItem
{
	char* name;
	int x, y; 
}; 

typedef struct MenuItem TKS_MenuItem; 

void setMenuItemName(TKS_MenuItem* item, char* name)
{
	int len = strlen(name);
	item->name = (char*)malloc(len);
	strcpy(item->name, name);
}

void setMenuItemCoords(TKS_MenuItem* item, int x, int y)
{
	item->x = x; 
	item->y = y;
}

struct Menu
{
	TKS_MenuItem* items;
	int length; 
	int max_length; 		
}; 

typedef struct Menu TKS_Menu;

TKS_Menu* TKS_createMenu()
{
	TKS_Menu* menu = (TKS_Menu*)malloc(sizeof(TKS_Menu*));
	menu->items = (TKS_MenuItem*)malloc(sizeof(TKS_MenuItem*));
	menu->length = 0; 
	menu->max_length = 50;
	return menu;
}

TKS_MenuItem* getLastMenuItem(TKS_Menu* menu)
{
	return menu->items + menu->length - 1; 
}

//int TKS_addItemToMenu(TKS_Menu* menu, TKS_MenuItem item)
//{
//	if (menu->length == menu->max_length - 1)
//	{
//		printf("ERROR Menu length is max!\n");
//		return 1;
//	}
//	
//	menu->length = menu->length + 2; 
// 
//	if (!realloc(menu->items, menu->length))
//	{
//		printf("ERROR Can't realloc\n");
//		return 1;
//	}
//		
//	menu->items[menu->length - 2] = item; 
//
//	return 0;
//}

int TKS_addMenuItem(TKS_Menu* menu, char* item_name)
{
	if (menu->length == menu->max_length)
	{
		printf("ERROR Menu length is max!\n");
		return 1;
	}
	
	menu->length = menu->length + 1; 
 
	if (!realloc(menu->items, menu->length))
	{
		printf("ERROR Can't realloc\n");
		return 1;
	}

	TKS_MenuItem* item;

	setMenuItemName(item, "name");
	 
	item->x = getLastMenuItem(menu)->x; 
	item->y = getLastMenuItem(menu)->y + 1; 
	
	setMenuItemName(getLastMenuItem(menu),  item->name);
	menu->items[menu->length].x = item->x; 
	menu->items[menu->length].y = item->y;

	return 0;
}

void printMenu(TKS_Menu menu)
{
	int i; 
	for(i = 0; i < menu.length; ++i)
	{
		printw(menu.items[i].name);
		printw("\n");
	}
}

int main(int argc, char** argv)
{
	TKS_Menu* menu = TKS_createMenu();	

	TKS_MenuItem item; 
	strcpy(item.name, "item");

	TKS_addMenuItem(menu, "item");
	TKS_addMenuItem(menu, "item");
	TKS_addMenuItem(menu, "item");

	printf("%s\n", menu->items[0].name);	

	//initscr();

	//int i; 
	//for(i = 0; i < menu->length; ++i)
	//{
	//	printw("%s ", menu->items[i].name);
	//}

	//printw("%s ", menu->items[0].name);

	//refresh();
	
	//getch();

	//endwin(); 

	return 0; 
}
