#include "../includes/addCopyToPotionBag.h"

int	addCopyToPotionBag(PotionBag *potions, Potion *potion)
{
	Potion *copy;

	copy = initPotion();
	if (!copy) {
		fputs("Error : Failed to initialize copy\n", stderr);
		return (0);
	}

	if (!potion) {
		fputs("Error : No potion provided\n", stderr);
		return (0);
	}

	if (!potions) {
		fputs("Error : No potion bag provided\n", stderr);
		return (0);
	}

	copy->name = MY_str_ncopy(potion->name, 0, MY_str_len(potion->name));
	copy->weight = potion->weight;
	copy->id = potion->id;
	copy->value = potion->value;
	copy->nb = potion->nb;
	copy->magnitude = potion->magnitude;
	copy->duration = potion->duration;
	copy->use = potion->use;

	if (!addToPotionBag(potions, copy)) {
		fputs("Error : Failed to add to potion bag\n", stderr);
		return (0);
	}

	return (1);
}
