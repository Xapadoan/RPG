#ifndef DEF_CHOOSE_MAP_ITEM_ACTION
#define DEF_CHOOSE_MAP_ITEM_ACTION

#include <stdio.h>

#include "Map.h"
#include "hashed_actions.h"
#include "map_action_list.h"

#include "MY_pow.h"

void	chooseMapItemAction(MapItem *item);
int	hashItemName(const char *name);

#endif
