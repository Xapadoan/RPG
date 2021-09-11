#ifndef DEF_COPY_TO_MAP_BAG
#define DEF_COPY_TO_MAP_BAG

#include "map_item.h"

#include <stdio.h>
#include <stdlib.h>

#include "MY_string.h"

#include "Map.h"
#include "addToMapBag.h"
#include "initMapItem.h"
#include "deleteMapItem.h"

#include "Hitbox.h"
#include "initHitbox.h"
#include "copyToHitbox.h"

int	copyToMapBag(MapBag *bag, MapItem *item);

#endif
