#include "../includes/deletePotion.h"

void	deletePotion(Potion *potion)
{
	if (potion->name)
		free(potion->name);

	potion->next = NULL;
	potion->use = NULL;
	free(potion);
}
