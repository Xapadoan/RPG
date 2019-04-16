#include "exchangePotion.h"

int		exchangePotion(Potion *potion, PotionBag *src_bag, PotionBag *dst_bag)
{
	if (!potion || !src_bag) {
		fputs("Error : Missing arguments for exchangePotion\n", stderr);
		return (0);
	} else if (!dst_bag) {
		dst_bag = initItemBag();
	}
	puts("echange potion not finihed");
	return (1);
}
