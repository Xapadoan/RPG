#include "../includes/initPotionBag.h"

PotionBag	*initPotionBag(void)
{
	PotionBag *potions;
	Potion *potion;

	potion = NULL;
	potions = NULL;

	potions = malloc(sizeof(*potions));
	if (!potions) {
		fputs("Memory Error : Failed to allocate memory for potion bag\n", stderr);
		return (NULL);
	}

	potion = initPotion();
	if (!potion) {
		fputs("Error : Failed to init potion\n", stderr);
		return (NULL);
	}

	potions->nb = 0;
	potion->value = 0;
	potion->weight = 0;
	potions->first = potion;
	return (potions);
}
