CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../includes/config\
				 -iquote ../../engine/includes\
				 -iquote ../../engine/font/includes\

OBJ=moveMainCursor.o\
		putMainChoices.o\
		putTitleScreen.o\
		useMainMenu.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

moveMainCursor.o: src/moveMainCursor.c\
	includes/moveMainCursor.h\
	includes/putMainChoices.h\
	../../engine/includes/endSDL.h\
	../../includes/config/interface_sprite.h
	$(CC) $(CC_FLAGS) $< -o $@

putMainChoices.o: src/putMainChoices.c\
	includes/putMainChoices.h\
	../../includes/config/font.h\
	../../engine/font/includes/putFontCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
putTitleScreen.o: src/putTitleScreen.c\
	includes/putTitleScreen.h\
	../../includes/config/font.h\
	../../includes/config/art.h\
	../../engine/font/includes/putFontCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
useMainMenu.o: src/useMainMenu.c\
	includes/useMainMenu.h\
	includes/putMainChoices.h\
	includes/moveMainCursor.h\
	includes/putTitleScreen.h\
	../../engine/includes/endSDL.h
	$(CC) $(CC_FLAGS) $< -o $@
