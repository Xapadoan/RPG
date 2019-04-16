#include "../includes/deletePotionBag.h"

void	deletePotionBag(PotionBag *potions)
{
	Potion *potion;

	potion = potions->first;
	while (potion) {
		potions->first = potion->next;
		deletePotion(potion);
		potion = potions->first;
	}

	free(potions);
}
