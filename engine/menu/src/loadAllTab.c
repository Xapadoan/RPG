#include "../includes/loadAllTab.h"

int	loadPotionsInTab(TabMenu *menu, PotionBag *potions)
{
	Potion *potion;

	potion = NULL;
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : Menu tab list are not initialized\n", stderr);
		return (0);
	}

	if (!potions) {
		fputs("Error : No potion bag provided\n", stderr);
		return (0);
	}

	potion = potions->first;
	while (potion) {
		if (!addPotionDataToTab(menu, potion, ALL_TAB_ID)) {
			fputs("Error : Failed to add potion data to tab\n", stderr);
			return (0);
		}
		potion = potion->next;
	}

	return (1);
}

int loadAllTab(TabMenu *menu, ItemBag *bag) {
	if (!loadPotionsInTab(menu, bag->potions)) {
		fputs("Error : Failed to load potions\n", stderr);
		return (0);
	}
	return (1);
}
