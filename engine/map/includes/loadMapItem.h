#ifndef DEF_LOAD_MAP_ITEM
#define DEF_LOAD_MAP_ITEM

#include "../../../includes/config/map_item.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_ncopy.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_split.h"

#include "../../../lib/libMY/libMY_int/includes/MY_str2int.h"

#include "../../../lib/libMY/libMY_array/includes/MY_free_2d_char.h"

#include "../../hitbox/includes/loadHitbox.h"
#include "../../location/includes/Direction.h"
#include "../../item/includes/loadItemContainerItems.h"

#include "Map.h"
#include "initMapItem.h"
#include "deleteMapItem.h"
#include "chooseMapItemAction.h"
#include "isItemContainer.h"

MapItem	*loadMapItem(FILE *file, const char *map_name);
int	loadMapItemSprite(MapItem *item, FILE *file, int nb_sprites);
int	loadMapItemHitbox(MapItem *item, const char *rot);

#endif
