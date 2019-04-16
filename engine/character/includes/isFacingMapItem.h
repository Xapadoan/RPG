#ifndef DEF_IS_FACING_MAP_ITEM
#define DEF_IS_FACING_MAP_ITEM

#include "../../../includes/config/map_item.h"

#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../map/includes/Map.h"
#include "../../hitbox/includes/restrictMovements.h"
#include "../../hitbox/includes/getHitboxDimensions.h"

#include "../../../lib/libMY/libMY_int/includes/MY_MIN.h"

#include "Team.h"

MapItem	*isFacingMapItem(Team *team, Map *map);

#endif
