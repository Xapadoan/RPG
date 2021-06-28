#ifndef DEF_TEAM
#define DEF_TEAM

#include "Location.h"
#include "Hitbox.h"
#include "Character.h"

typedef struct Team {
	struct Character heroes[4];
	struct Location location;
	struct Hitbox *hitbox;
	struct ItemBag *bag;
} Team;

#endif
