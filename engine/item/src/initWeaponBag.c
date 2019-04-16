#include "../includes/initWeaponBag.h"

WeaponBag	*initWeaponBag(void)
{
	WeaponBag *bag;
	Weapon *weapon;

	weapon = NULL;
	bag = NULL;

	bag = malloc(sizeof(*bag));
	if (!bag) {
		fputs("Memory Error : Failed to allocate memory for weapon bag\n", stderr);
		return (NULL);
	}

	weapon = initWeapon();
	if (!weapon) {
		fputs("Error : Failed to initialize weapon\n", stderr);
		free(bag);
		return (NULL);
	}

	bag->nb = 0;
	bag->value = 0;
	bag->weight = 0;
	bag->first = weapon;

	return (bag);
}
