#ifndef DEF_ADD_COPY_TO_POTION_BAG
#define DEF_ADD_COPY_TO_POTION_BAG

#include "../../../includes/config/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_ncopy.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"

#include "Potion.h"
#include "initPotion.h"
#include "addToPotionBag.h"

int	addCopyToPotionBag(PotionBag *potions, Potion *potion);

#endif
