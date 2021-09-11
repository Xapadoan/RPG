CC=gcc
CC_FLAGS=-g\
				 -Wall\
				 -Wextra\
				 -Werror\
				 -c\
				 -iquote includes\

OBJ=startPlayingMusic.o\
		stopPlayingMusic.o

all: $(OBJ)

clean:
	rm -f $(OBJ)

re: clean $(OBJ)

startPlayingMusic.o: src/startPlayingMusic.c\
	includes/startPlayingMusic.h
	$(CC) $(CC_FLAGS) $< -o $@

stopPlayingMusic.o: src/stopPlayingMusic.c\
	includes/stopPlayingMusic.h
	$(CC) $(CC_FLAGS) $< -o $@
