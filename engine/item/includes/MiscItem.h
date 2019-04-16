#ifndef DEF_MISC_ITEM
#define DEF_MISC_ITEM

#include <SDL/SDL.h>

#define MISC_ITEM_UNUSABLE 0b0000
#define MISC_ITEM_COOKING 0b0001
#define MISC_ITEM_ALCHEMY 0b0010
#define MISC_ITEM_SMITH 0b0100

typedef struct MiscBag {
	unsigned int nb;
	unsigned int weight;
	unsigned int value;
	struct MiscItem *first;
} MiscBag;

typedef struct MiscItem {
	char *name;
	unsigned int id;
	unsigned int nb;
	unsigned int weight;
	unsigned int value;
	unsigned int usage;
	SDL_Surface *preview;
	struct MiscItem *next;
} MiscItem;

#endif
