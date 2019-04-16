#include "../includes/deleteWeaponBag.h"

void	deleteWeaponBag(WeaponBag *bag)
{
	Weapon *weapon;

	weapon = bag->first;
	while (weapon) {
		bag->first = weapon->next;
		deleteWeapon(weapon);
		weapon = bag->first;
	}

	free(bag);
}
