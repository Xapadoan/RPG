CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY/libMY_string/includes

OBJ=deleteLocation.o\
	initLocation.o\
	setLocationMap.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

deleteLocation.o: src/deleteLocation.c\
	includes/deleteLocation.h\
	includes/Location.h
	$(CC) $(CC_FLAGS) $< -o $@
initLocation.o: src/initLocation.c\
	includes/initLocation.h\
	includes/Location.h
	$(CC) $(CC_FLAGS) $< -o $@
setLocationMap.o: src/setLocationMap.c\
	includes/setLocationMap.h\
	includes/Location.h\
	../../lib/libMY/libMY_string/includes/MY_str_len.h\
	../../lib/libMY/libMY_string/includes/MY_clear_string.h\
	../../lib/libMY/libMY_string/includes/MY_str_append.h
	$(CC) $(CC_FLAGS) $< -o $@
