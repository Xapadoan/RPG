#ifndef DEF_CHOOSE_MAP_ITEM_ACTION
#define DEF_CHOOSE_MAP_ITEM_ACTION

#include <stdio.h>

#include "Map.h"
#include "../map_item_action/includes/hashed_actions.h"
#include "../map_item_action/includes/map_action_list.h"

#include "../../../lib/libMY/libMY_int/includes/MY_pow.h"

void	chooseMapItemAction(MapItem *item);
int	hashItemName(const char *name);

#endif
