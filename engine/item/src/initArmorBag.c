#include "../includes/initArmorBag.h"

ArmorBag *initArmorBag(void)
{
	ArmorBag *bag;
	Armor *armor;

	armor = NULL;
	bag = NULL;

	bag = malloc(sizeof(*bag));
	if (!bag) {
		fputs("Memory Error : Failed to allocate memory for armor bag\n", stderr);
		return (NULL);
	}

	armor = initArmor();
	if (!armor) {
		fputs("Error : Failed to initialize armor\n", stderr);
		free(bag);
		return (NULL);
	}

	bag->nb = 0;
	bag->value = 0;
	bag->weight = 0;
	bag->first = armor;

	return (bag);
}
