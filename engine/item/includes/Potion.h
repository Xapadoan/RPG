#ifndef DEF_POTION
#define DEF_POTION

#include <SDL/SDL.h>

#include "../../character/includes/Character.h"

typedef struct PotionBag {
	unsigned int nb;
	unsigned int value;
	unsigned int weight;
	struct Potion *first;
} PotionBag;

typedef struct Potion {
	char *name;
	unsigned int id;
	unsigned int weight;
	unsigned int value;
	unsigned int nb;
	int magnitude;
	unsigned int duration;
	struct Potion *next;
	int (*use)(struct Potion *self, Character *character);
} Potion;

#endif
