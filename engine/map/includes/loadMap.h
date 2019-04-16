#ifndef DEF_LOAD_MAP
#define DEF_LOAD_MAP

#include "../../../includes/config/map.h"

#include <stdio.h>
#include <stdlib.h>

#include "loadYMap.h"
#include "Map.h"
#include "loadMapStructures.h"
#include "loadMapBag.h"
#include "../../hitbox/includes/loadHitbox.h"
#include "../../character/includes/Team.h"
#include "../../display/includes/displayHitbox.h"

int	loadMap(Map *map, const char *map_name);

#endif
