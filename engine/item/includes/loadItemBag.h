#ifndef DEF_LOAD_ITEM_BAG
#define DEF_LOAD_ITEM_BAG

#include "../../../includes/config/item.h"

#include <stdio.h>

#include "../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h"

#include "item_categories.h"

#include "ItemBag.h"
#include "initItemBag.h"
#include "loadPotionBag.h"

int	loadItemBag(ItemBag *bag, FILE *file);

#endif
