#include "loadItemExchangeMenuContent.h"

int	loadItemExchangeMenuContent(TabMenu *menu, ItemBag *bag)
{
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!bag) {
		fputs("Error : No item bag provided\n", stderr);
		return (0);
	}

	//Create armor tab and add to menu_tabs
	if (!loadArmorTab(menu, bag->armors)) {
		fputs("Error : Failed to load armors on menu\n", stderr);
		return (0);
	}

	//Create book tab and add to menu_tabs
	if (!loadBookTab(menu, bag->books)) {
		fputs("Error : Failed to load books on menu\n", stderr);
		return(0);
	}

	//Create misc_item tab and add to menu_tabs
	if (!loadMiscItemTab(menu, bag->miscs)) {
		fputs("Error : Failed to load misc items on menu\n", stderr);
		return (0);
	}

	//Create potion tab and add to menu_tabs
	if (!loadPotionTab(menu, bag->potions)) {
		fputs("Error : Failed to load potions on menu\n", stderr);
		return (0);
	}

	//Create weapon tab and add to menu_tabs
	if (!loadWeaponTab(menu, bag->weapons)) {
		fputs("Error : Failed to load weapons on menu\n", stderr);
		return (0);
	}

	return (1);
}
