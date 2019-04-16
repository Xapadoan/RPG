#include "../includes/createItemExchangeTabs.h"

int	createItemExchangeTabs(TabMenu *menu) {
	Tab *book_tab;
	Tab *misc_tab;
	Tab *armor_tab;
	Tab *weapon_tab;
	Tab *potion_tab;
	Tab *all_tab;

	all_tab = NULL;
	potion_tab = NULL;
	misc_tab = NULL;
	book_tab = NULL;
	weapon_tab = NULL;
	armor_tab = NULL;
	if (!menu) {
		fputs("Arg Error : Missing arguments for createItemExchangeTabs\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : menu tabs were not initialized\n", stderr);
		return (0);
	}

	//Create Misc Tab
	misc_tab = initTab();
	if (!misc_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	misc_tab->id = MISC_TAB_ID;
	misc_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = misc_tab;
	misc_tab->previous = NULL;
	menu->tabs->first = misc_tab;

	//Create Book Bag
	book_tab = initTab();
	if (!book_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	book_tab->id = BOOK_TAB_ID;
	book_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = book_tab;
	book_tab->previous = NULL;
	menu->tabs->first = book_tab;

	//Create Potion Bag
	potion_tab = initTab();
	if (!potion_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	potion_tab->id = POTION_TAB_ID;
	potion_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = potion_tab;
	potion_tab->previous = NULL;
	menu->tabs->first = potion_tab;

	//Create Weapon Bag
	weapon_tab = initTab();
	if (!weapon_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	weapon_tab->id = WEAPON_TAB_ID;
	weapon_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = weapon_tab;
	weapon_tab->previous = NULL;
	menu->tabs->first = weapon_tab;

	//Create Armor Tab
	armor_tab = initTab();
	if (!armor_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	armor_tab->id = ARMOR_TAB_ID;
	armor_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = armor_tab;
	armor_tab->previous = NULL;
	menu->tabs->first = armor_tab;

	//Create All Tab
	all_tab = initTab();
	if (!all_tab) {
		fputs("Error : Failed to initialize tab\n", stderr);
		return (0);
	}
	all_tab->id = ALL_TAB_ID;
	all_tab->next = menu->tabs->first;
	if (menu->tabs->first)
		menu->tabs->first->previous = all_tab;
	all_tab->previous = NULL;
	menu->tabs->first = all_tab;

	menu->tabs->nb_tabs = 6;
	return (1);
}
