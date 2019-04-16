#include "../includes/loadPotionBag.h"

int	loadPotionBag(PotionBag *potions, FILE *file)
{
	char line[50];
	int value;
	Potion *potion;

	value = 0;
	potion = initPotion();
	if (!potion) {
		fputs("Error : Failed to initialize potion\n", stderr);
		return (0);
	}

	do {
		//Scan potion name;nb;id
		value = fscanf(file, "%s\t%u\t%x\n", line, &(potion->nb), &(potion->id));
		if (value == 0 || value == EOF) {
			deletePotion(potion);
			return (1);
		}
		//Copy potion name and store in potion
		potion->name = MY_str_ncopy(line, 0, MY_str_len(line));
		if (!potion->name) {
			fputs("Error : Failed to copy line\n", stderr);
			return (0);
		}

		//Set other data
		if (!setPotionData(potion)) {
			fputs("Error : Failed to set potion data\n", stderr);
			return (0);
		}

		//Add to bag
		if (!addCopyToPotionBag(potions, potion)) {
			fputs("Error : Failed to add potion to potion bag\n", stderr);
			return (0);
		}
		free(potion->name);
		potion->name = NULL;
	} while (value != 0 && value != EOF);

	deletePotion(potion);
	return (1);
}
