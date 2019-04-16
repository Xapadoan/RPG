#ifndef DEF_TEAM
#define DEF_TEAM

#include "../../location/includes/Location.h"
#include "../../hitbox/includes/Hitbox.h"
#include "Character.h"

typedef struct Team {
	struct Character heroes[4];
	struct Location location;
	struct Hitbox *hitbox;
	struct ItemBag *bag;
} Team;

#endif
