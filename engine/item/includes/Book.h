#ifndef DEF_BOOK
#define DEF_BOOK

#include <SDL/SDL.h>

typedef struct BookBag {
	unsigned int nb;
	unsigned int weight;
	unsigned int value;
	struct Book *first;
} BookBag;

typedef struct Book {
	char *name;
	unsigned int weight;
	unsigned int value;
	SDL_Surface *preview;
	int (*read)(struct Book *self, SDL_Surface *screen);
	struct Book *next;
} Book;

#endif
