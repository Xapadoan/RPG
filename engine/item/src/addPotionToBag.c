#include "../includes/addPotionToBag.h"

int	addPotionToBag(Potion *potion, unsigned int nb, PotionBag *bag)
{
	Potion *current;

	current = NULL;

	if (!bag) {
		fputs("Error : No potion bag provided\n", stderr);
		return (0);
	}

	if (!potion) {
		fputs("Error : No potion provided\n", stderr);
		return (0);
	}

	current = bag->first;

	// Find it in potion bag
	while (current && current->id != potion->id)
		current = current->next;

	if (!current) {
		current = copyPotion(potion);
		if (!current) {
			fputs("Error : Failed to copy potion\n", stderr);
			return (0);
		}
		current->next = bag->first;
		bag->first = current;
	} else {
		current->nb += nb;
	}

	bag->weight += potion->weight * nb;
	bag->value += potion->value * nb;

	return (1);
}
