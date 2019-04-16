#include "../includes/deleteArmorBag.h"

void	deleteArmorBag(ArmorBag *bag)
{
	Armor *armor;

	armor = bag->first;
	while (armor) {
		bag->first = armor->next;
		deleteArmor(armor);
		armor = bag->first;
	}

	free(bag);
}
