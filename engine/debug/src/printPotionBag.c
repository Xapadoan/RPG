#include "printPotionBag.h"

void	printPotionBag(PotionBag *bag, int flags)
{
	Potion	*potion;

	potion = NULL;
	if (!bag) {
		puts("\n --- NO PotionBag ---\n");
		return;
	}
	puts("\n--- PotionBag ---\n");
	printf("nb: %d\tvalue: %d\tweight: %d\n", bag->nb, bag->value, bag->weight);
	if (!(flags & 1)) return;
	potion = bag->first;
	while (potion) {
		printPotion(potion);
		potion = potion->next;
	}
	puts("-------------------\n");
}
