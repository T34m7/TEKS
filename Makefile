CC=gcc 
CCFLGS=-Wall -o
LIB=-lncurses

EXAMPLES=code_examples

all: 
	$(CC) $(CCFLGS) main.c $(LIB)

hello-world: 
	$(CC)$(CCFLGS) example  $(EXAMPLES)/hello_world.c $(LIB)
	./example

keys-pressed:
	$(CC)$(CCFLGS) example $(EXAMPLES)/keys_pressed.c $(LIB)
	./example

keys-pressed-new:
	$(CC)$(CCFLGS) example $(EXAMPLES)/keys_pressed_new.c $(LIB)
	./example

save-to-file:
	$(CC)$(CCFLGS) example $(EXAMPLES)/save_to_file.c $(LIB)
	./example

save-to-new-file:
	$(CC)$(CCFLGS) example $(EXAMPLES)/save_to_new_file.c $(LIB)
	./example

output:
	$(CC)$(CCFLGS) example $(EXAMPLES)/output.c $(LIB)
	./example

input: 
	$(CC)$(CCFLGS) example $(EXAMPLES)/input.c $(LIB)
	./example

menu: 
	$(CC)$(CCFLGS) example $(EXAMPLES)/menu.c $(LIB)
	./example

menu-choose: 
	$(CC)$(CCFLGS) example $(EXAMPLES)/menu_choose.c $(LIB)
	./example

nncurse-windows: 
	$(CC)$(CCFLGS) example $(EXAMPLES)/ncurse_windows.c $(LIB)
	./example

borders:	
	$(CC)$(CCFLGS) example $(EXAMPLES)/borders.c $(LIB)
	./example

colors: 
	$(CC)$(CCFLGS) example $(EXAMPLES)/colors.c $(LIB)
	./example

clean: 
	rm example
