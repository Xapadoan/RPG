#ifndef DEF_EXCHANGE_POTION
#define DEF_EXCHANGE_POTION

#include <stdio.h>

#include "initPotionBag.h"
#include "addPotionToBag.h"
#include "removePotionFromBag.h"

int	exchangePotion(unsigned int potion_id, PotionBag *src_bag, PotionBag *dst_bag);

#endif
