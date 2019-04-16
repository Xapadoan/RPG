#include "../includes/loadPotionTab.h"

int	loadPotionTab(TabMenu *menu, PotionBag *potions)
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
	while (potion->next) {
		if (!addPotionDataToTab(menu, potion)) {
			fputs("Error : Failed to add potion data to tag\n", stderr);
			return (0);
		}
		potion = potion->next;
	}

	return (1);
}
