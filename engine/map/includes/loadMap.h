#ifndef DEF_LOAD_MAP
#define DEF_LOAD_MAP

#include "map.h"

#include <stdio.h>
#include <stdlib.h>

#include "loadYMap.h"
#include "Map.h"
#include "loadMapStructures.h"
#include "loadMapBag.h"
#include "loadHitbox.h"
#include "Team.h"
#include "displayHitbox.h"

int	loadMap(Map *map, const char *map_name);

#endif
