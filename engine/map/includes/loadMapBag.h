#ifndef DEF_LOAD_MAP_BAG
#define DEF_LOAD_MAP_BAG

#include <stdio.h>
#include <stdlib.h>

#include "../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h"

#include "Map.h"
#include "loadMapItem.h"
#include "addToMapBag.h"
#include "openMapItemList.h"

int	loadMapBag(MapBag *bag, const char *map_name);

#endif
