#ifndef DEF_LOAD_MAP_ITEM_CONTAINER_ITEMS
#define DEF_LOAD_MAP_ITEM_CONTAINER_ITEMS

#include <stdio.h>
#include <stdlib.h>

#include "../../../includes/config/map_item.h"
#include "../../../includes/config/map.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

#include "../../../lib/libMY/libMY_int/includes/MY_hex2char.h"

#include "../../map/includes/Map.h"
#include "../../map/includes/isItemContainer.h"

#include "loadItemBag.h"

int	loadItemContainerItems(MapItem *container, const char *map_name);

#endif
