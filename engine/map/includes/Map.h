#ifndef DEF_MAP
#define DEF_MAP

#include <SDL/SDL.h>

#include "../../character/includes/Team.h"
#include "../../hitbox/includes/Hitbox.h"
#include "../../item/includes/ItemBag.h"

typedef struct Map {
	SDL_Surface *background;
	Hitbox *hitbox;
	struct MapBag *items;
} Map;

typedef struct MapItem {
	unsigned int id;
	SDL_Surface *sprite;
	SDL_Rect pos;
	Hitbox *hitbox;
	ItemBag *items;
	char *name;
	int (*action)(struct MapItem *self, struct Map *map, Team *team, SDL_Surface *screen, char **argv);
	int dir;
	struct MapItem *next;
} MapItem;

typedef struct MapBag {
	MapItem *first;
	int len;
} MapBag;

#endif
