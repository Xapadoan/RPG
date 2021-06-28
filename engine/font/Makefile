CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY/libMY_string/includes

OBJ=putFont.o\
		putFontCenter.o\
		putFontColumn.o

putFont.o: src/putFont.c\
	includes/putFont.h
	$(CC) $(CC_FLAGS) $< -o $@
putFontCenter.o: src/putFontCenter.c\
	includes/putFontCenter.h
	$(CC) $(CC_FLAGS) $< -o $@
putFontColumn.o: src/putFontColumn.c\
	includes/putFontColumn.h\
	includes/putFont.h\
	../../lib/libMY/libMY_string/includes/MY_clear_string.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)
