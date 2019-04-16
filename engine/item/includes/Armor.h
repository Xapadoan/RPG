#ifndef DEF_ARMOR
#define DEF_ARMOR

#include <SDL/SDL.h>

#include "../../display/includes/SpriteList.h"

typedef struct ArmorBag {
	unsigned int nb;
	unsigned int weight;
	unsigned int value;
	struct Armor *first;
} ArmorBag;

typedef struct Armor {
	char *name;
	int	is_equiped;
	unsigned int weight;
	unsigned int value;
	unsigned int rating;
	unsigned int part;
	SDL_Surface *preview;
	SpriteList *sprites;
	struct Armor *next;
} Armor;

#endif
