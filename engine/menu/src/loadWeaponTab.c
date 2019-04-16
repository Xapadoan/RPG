#include "../includes/loadWeaponTab.h"

int	loadWeaponTab(TabMenu *menu, WeaponBag *weapons) {
	Weapon *weapon;

	weapon = NULL;
	if (!menu | !weapons) {
		fputs("Error : Missing arguments for load Weapon Tab\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : Menu tab list are not initialized\n", stderr);
		return (0);
	}

	weapon = weapons->first;
	while (weapon->next) {
		if (!addWeaponDataToTab(menu, weapon)) {
			fputs("Error : Failed to add weapon data to tab\n", stderr);
			return (0);
		}
		weapon = weapon->next;
	}

	return (1);
}
