#include "../includes/initPotionBag.h"

PotionBag	*initPotionBag(void)
{
	PotionBag *potions;

	potions = NULL;

	potions = malloc(sizeof(*potions));
	if (!potions) {
		fputs("Memory Error : Failed to allocate memory for potion bag\n", stderr);
		return (NULL);
	}

	potions->nb = 0;
	potions->value = 0;
	potions->weight = 0;
	potions->first = NULL;
	return (potions);
}
