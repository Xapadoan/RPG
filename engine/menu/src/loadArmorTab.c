#include "loadArmorTab.h"

int	loadArmorTab(TabMenu *menu, ArmorBag *armors) {
	Armor *armor;

	armor = NULL;
	if (!menu | !armors) {
		fputs("Error : Missing arguments for load Armor Tab\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : Menu tab list are not initialized\n", stderr);
		return (0);
	}

	armor = armors->first;
	while (armor->next) {
		if (!addArmorDataToTab(menu, armor)) {
			fputs("Error : Failed to add armor data to tab\n", stderr);
			return (0);
		}
		armor = armor->next;
	}

	return (1);
}
