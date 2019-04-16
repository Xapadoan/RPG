#include "../includes/initItemBag.h"

ItemBag	*initItemBag(void)
{
	ItemBag *bag;

	bag = NULL;
	bag = malloc(sizeof(*bag));
	if (!bag) {
		fputs("Memory Error : Failed to allocate memory for item bag\n", stderr);
		return (NULL);
	}

	bag->copper = 0;
	bag->potions = initPotionBag();
	if (!bag->potions) {
		fputs("Error : Failed to initialize potion bag\n", stderr);
		return (NULL);
	}

	bag->armors = initArmorBag();
	if (!bag->armors) {
		fputs("Error : Failed to initialize armor bag\n", stderr);
		return (NULL);
	}

	bag->weapons = initWeaponBag();
	if (!bag->weapons) {
		fputs("Error : Failed to initialize weapon bag\n", stderr);
		return (NULL);
	}

	bag->books = initBookBag();
	if (!bag->books) {
		fputs("Error : Failed to initialize book bag\n", stderr);
		return (NULL);
	}

	bag->miscs = initMiscBag();
	if (!bag->miscs) {
		fputs("Error : Failed to initialize misc bag\n", stderr);
		return (NULL);
	}

	return (bag);
}
