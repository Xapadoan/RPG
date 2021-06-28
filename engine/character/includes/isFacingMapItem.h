#ifndef DEF_IS_FACING_MAP_ITEM
#define DEF_IS_FACING_MAP_ITEM

#include "map_item.h"

#include <stdlib.h>
#include <SDL/SDL.h>

#include "Map.h"
#include "restrictMovements.h"
#include "getHitboxDimensions.h"

#include "MY_MIN.h"

#include "Team.h"

MapItem	*isFacingMapItem(Team *team, Map *map);

#endif
