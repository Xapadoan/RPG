#include "removePotionFromBag.h"

int	removePotionFromBag(unsigned int potion_id, unsigned int nb, PotionBag *bag) {
	Potion	*current;
	Potion	*tmp;

	current = bag->first;
	tmp = NULL;
	while (current && current->id != potion_id)
		current = current->next;

	if (!current) {
		fputs("Warning : Potion was not found in bag\n", stderr);
		return (0);
	}

	if (current->nb < nb)
		fputs("Warning : Not enough potions \n", stderr);

	if (current->nb <= nb) {
		if (bag->first->id == current->id) {
			bag->first = current->next;
		} else {
			tmp = bag->first;
			while (tmp->next && tmp->next->id != current->id)
				tmp = tmp->next;
			tmp->next = current->next;
		}
		bag->weight -= current->weight * current->nb;
		deletePotion(current);
	} else {
		bag->weight -= current->weight * nb;
		current->nb -= nb;
	}

	current = NULL;
	tmp = NULL;
	return (1);
}
