#include "../includes/addToPotionBag.h"

int	addToPotionBag(PotionBag *bag, Potion *potion)
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
	while (current->next) {
		if (current->id == potion->id)
			current->nb += potion->nb;
		current = current->next;
	}

	if (!current->next) {
		potion->next = bag->first;
		bag->first = potion;
	}

	bag->weight += potion->weight * potion->nb;
	bag->value += potion->value * potion->nb;

	return (1);
}
