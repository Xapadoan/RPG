#ifndef DEF_LOAD_POTION_BAG
#define DEF_LOAD_POTION_BAG

#include <stdio.h>
#include <stdlib.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_capitalize.h"

#include "initPotion.h"
#include "setPotionData.h"
#include "addCopyToPotionBag.h"

int	loadPotionBag(PotionBag *potions, FILE *file);

#endif
