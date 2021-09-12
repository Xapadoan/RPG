#include "copyPotion.h"

Potion	*copyPotion(Potion *potion) {
	Potion	*copy;

	copy = initPotion();
	if (!copy) {
		fputs("Error : Failed to initialize copy\n", stderr);
		return (NULL);
	}

	copy->name = MY_str_ncopy(potion->name, 0, MY_str_len(potion->name));
	copy->weight = potion->weight;
	copy->id = potion->id;
	copy->value = potion->value;
	copy->nb = potion->nb;
	copy->magnitude = potion->magnitude;
	copy->duration = potion->duration;
	copy->use = potion->use;

	return (copy);
}
