#ifndef DEF_GET_MAP_HITBOX
#define DEF_GET_MAP_HITBOX

#include "../../map/includes/Map.h"
#include "Hitbox.h"
#include "initHitbox.h"
#include "mergeHitboxes.h"

Hitbox	*getMapHitbox(Map *map);

/*
 * RETURN VALUE :
 * 	This function returns the total hitbox of a map (structure and items).
 */

#endif
