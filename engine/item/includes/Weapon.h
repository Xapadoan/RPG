#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <SDL/SDL.h>

#include "../../display/includes/SpriteList.h"

typedef struct WeaponBag {
	unsigned int nb;
	unsigned int weight;
	unsigned int value;
	struct Weapon *first;
} WeaponBag;

typedef struct Weapon {
	char *name;
	int is_equiped;
	unsigned int weight;
	unsigned int value;
	unsigned int dammage;
	unsigned int crit_chance;
	SDL_Surface *preview;
	SpriteList *sprites;
	struct Weapon *next;
} Weapon;

#endif
