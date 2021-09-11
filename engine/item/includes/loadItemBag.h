#ifndef DEF_LOAD_ITEM_BAG
#define DEF_LOAD_ITEM_BAG

#include "item.h"

#include <stdio.h>

#include "MY_file.h"

#include "item_categories.h"

#include "ItemBag.h"
#include "initItemBag.h"
#include "loadPotionBag.h"

int	loadItemBag(ItemBag *bag, FILE *file);

#endif
