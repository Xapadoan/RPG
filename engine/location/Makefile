CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\
				 -iquote ../../lib/libMY

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
	../../lib/libMY/MY_string.h
	$(CC) $(CC_FLAGS) $< -o $@
