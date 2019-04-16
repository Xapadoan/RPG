#include "deleteItemBag.h"

void	deleteItemBag(ItemBag *bag)
{
	deletePotionBag(bag->potions);
	deleteArmorBag(bag->armors);
	deleteWeaponBag(bag->weapons);
	deleteBookBag(bag->books);
	deleteMiscBag(bag->miscs);
	free(bag);
	bag = NULL;
}
