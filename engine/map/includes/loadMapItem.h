#ifndef DEF_LOAD_MAP_ITEM
#define DEF_LOAD_MAP_ITEM

#include "map_item.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>

#include "MY_string.h"
#include "MY_convert.h"
#include "MY_array.h"

#include "loadHitbox.h"
#include "Direction.h"
#include "loadItemContainerItems.h"

#include "Map.h"
#include "initMapItem.h"
#include "deleteMapItem.h"
#include "chooseMapItemAction.h"
#include "isItemContainer.h"

MapItem	*loadMapItem(FILE *file, const char *map_name);
int	loadMapItemSprite(MapItem *item, FILE *file, int nb_sprites);
int	loadMapItemHitbox(MapItem *item, const char *rot);

#endif
