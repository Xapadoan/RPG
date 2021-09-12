#include "exchangePotion.h"

int		exchangePotion(unsigned int potion_id, PotionBag *src_bag, PotionBag *dst_bag)
{
	Potion	*src_potion;

	src_potion = NULL;
	if (!src_bag) {
		fputs("Error : Missing arguments for exchangePotion\n", stderr);
		return (0);
	} else if (!dst_bag) {
		dst_bag = initPotionBag();
	}

	// Find potion in src bag
	src_potion = src_bag->first;
	while (src_potion && src_potion->id != potion_id) {
		src_potion = src_potion->next;
	}
	if (!src_potion) {
		fputs("Error : Failed to find src_potion in src_potion bag\n", stderr);
		return (0);
	}

	// Adds to dst bag
	if (!addPotionToBag(src_potion, 1, dst_bag)) {
		fputs("Error : Failed to add src potion to dst bag\n", stderr);
		return (0);
	}


	// Remove from src bag
	if (!removePotionFromBag(potion_id, 1, src_bag))
		fputs("Warning : Something went wrong when removing potion from src bag\n", stderr);

	return (1);
}
