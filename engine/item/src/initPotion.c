#include "../includes/initPotion.h"

Potion	*initPotion(void)
{
	Potion *potion;

	potion = NULL;
	potion = malloc(sizeof(*potion));
	if (!potion) {
		fputs("Memory Error : Failed to allocate memory for potion\n", stderr);
		return (NULL);
	}

	potion->id = 0;
	potion->name = NULL;
	potion->weight = ITEM_POTION_DEFAULT_WEIGHT;
	potion->value = 0;
	potion->nb = 0;
	potion->magnitude = 0;
	potion->duration = 0;
	potion->next = NULL;
	potion->use = NULL;

	return (potion);
}
