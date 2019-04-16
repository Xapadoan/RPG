#ifndef DEF_ITEM_BAG
#define DEF_ITEM_BAG

#include "Potion.h"
#include "Armor.h"
#include "Weapon.h"
#include "Book.h"
#include "MiscItem.h"

typedef struct ItemBag {
	unsigned int copper;
	PotionBag *potions;
	ArmorBag *armors;
	WeaponBag *weapons;
	BookBag *books;
	MiscBag *miscs;
} ItemBag;

#endif
