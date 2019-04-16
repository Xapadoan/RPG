#include "../includes/loadItemBag.h"

int	loadItemBag(ItemBag *bag, FILE *file)
{
	int item_category;

	item_category = 0;
	if (!file) {
		fputs("Error : No file provided\n", stderr);
		return (0);
	}

	if (!bag) {
		bag = initItemBag();
		if (!bag) {
			fputs("Error : Failed to initialize item bag\n", stderr);
			return (0);
		}
	}

	//Store copper
	fscanf(file, "%u\n", &bag->copper);

	//Scan item category and load appropriate bag
	while (fscanf(file, "%x\t%*s", &item_category) != EOF) {
		switch (item_category) {
			case (ITEM_CATEGORY_ARMOR) :
				fputs("loadArmorBag is not implemented yet!\n", stderr);
				break;
			case (ITEM_CATEGORY_BOOK) :
				fputs("loadBookBag is not implemented yet!\n", stderr);
				break;
			case (ITEM_CATEGORY_MISC) :
				fputs("loadMiscBag is not implemented yet!\n", stderr);
				break;
			case (ITEM_CATEGORY_POTION) :
				if (!loadPotionBag(bag->potions, file)) {
					fputs("Error : Failed to load potion bag\n", stderr);
					return (0);
				}
				break;
			case (ITEM_CATEGORY_WEAPON) :
				fputs("loadWeaponBag is not implemented yet!\n", stderr);
				break;
			default :
				fprintf(stderr, "Error : Unknown item category (%d)\n", item_category);
				return (0);
				break;
		}
	}

	return (1);
}
