#ifndef DEF_COPY_TO_MAP_BAG
#define DEF_COPY_TO_MAP_BAG

#include "../../../includes/config/map_item.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_ncopy.h"

#include "Map.h"
#include "addToMapBag.h"
#include "initMapItem.h"
#include "deleteMapItem.h"

#include "../../hitbox/includes/Hitbox.h"
#include "../../hitbox/includes/initHitbox.h"
#include "../../hitbox/includes/copyToHitbox.h"

int	copyToMapBag(MapBag *bag, MapItem *item);

#endif
