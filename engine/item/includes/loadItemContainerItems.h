#ifndef DEF_LOAD_MAP_ITEM_CONTAINER_ITEMS
#define DEF_LOAD_MAP_ITEM_CONTAINER_ITEMS

#include <stdio.h>
#include <stdlib.h>

#include "map_item.h"
#include "map.h"

#include "MY_str_len.h"
#include "MY_str_append.h"

#include "MY_hex2char.h"

#include "Map.h"
#include "isItemContainer.h"

#include "loadItemBag.h"

int	loadItemContainerItems(MapItem *container, const char *map_name);

#endif
