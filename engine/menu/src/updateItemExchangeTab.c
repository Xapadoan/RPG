#include "updateItemExchangeTab.h"

int updateAllTab(TabMenu *menu, ItemBag *bag) {
	Tab	*current_tab;
	Tab	*tmp_next;
	Tab	*tmp_previous;

	current_tab = menu->tabs->first;
	tmp_next = NULL;
	tmp_previous = NULL;
	// Find all tab
	while (current_tab->id != ALL_TAB_ID)
		current_tab = current_tab->next;
	if (!current_tab) {
		fputs("Warning : Failed to find all tab\n", stderr);
		return (0);
	}

	// Reset tab
	tmp_next = current_tab->next;
	tmp_previous = current_tab->previous;
	deleteTab(current_tab);
	current_tab = initTab();
	if (!current_tab) {
		fputs("Error : Failed to init all tab\n", stderr);
		return (0);
	}
	current_tab->id = ALL_TAB_ID;
	current_tab->next = tmp_next;
	current_tab->previous = tmp_previous;
	if (tmp_previous)
		tmp_previous->next = current_tab;
	else
		menu->tabs->first = current_tab;
	if (tmp_next)
		tmp_next->previous = current_tab;
	else
		menu->tabs->first->next = current_tab;
	if (!loadAllTab(menu, bag)) {
		fputs("Warning : Failed to load all tab\n", stderr);
		return (0);
	}
	return (1);
}

int	updatePotionTab(TabMenu *menu, PotionBag *bag) {
	Tab	*current_tab;
	Tab	*tmp_next;
	Tab	*tmp_previous;

	current_tab = menu->tabs->first;
	tmp_next = NULL;
	tmp_previous = NULL;
	// Find potion tab
	while (current_tab->id != POTION_TAB_ID)
		current_tab = current_tab->next;
	if (!current_tab) {
		fputs("Warning : Failed to find potion tab\n", stderr);
		return (0);
	}

	// Reset tab
	tmp_next = current_tab->next;
	tmp_previous = current_tab->previous;
	deleteTab(current_tab);
	current_tab = initTab();
	if (!current_tab) {
		fputs("Error : Failed to init potion tab\n", stderr);
		return (0);
	}
	current_tab->id = POTION_TAB_ID;
	current_tab->next = tmp_next;
	current_tab->previous = tmp_previous;
	if (tmp_previous)
		tmp_previous->next = current_tab;
	else
		menu->tabs->first = current_tab;
	if (tmp_next)
		tmp_next->previous = current_tab;
	else
		menu->tabs->first->next = current_tab;
	if (!loadPotionTab(menu, bag)) {
		fputs("Warning : Failed to load potion tab\n", stderr);
		return (0);
	}
	return (1);
}

int	updateItemExchangeTab(TabMenu *menu) {
	switch (menu->active_tab) {
		case (ALL_TAB_ID):
			if (!updateAllTab(menu, ((MapItem *)menu->refs[1])->items)) {
				fputs("Error : Failed to update all entries\n", stderr);
				return (0);
			}
			break;
		case (ARMOR_TAB_ID):
		case (WEAPON_TAB_ID):
		case (BOOK_TAB_ID):
		case (MISC_TAB_ID):
		case (POTION_TAB_ID):
			if (!updatePotionTab(menu, ((MapItem *)menu->refs[1])->items->potions)) {
				fputs("Error : Failed to update potion entries\n", stderr);
				return (0);
			}
			break;
		default:
			fputs("Unknown tab id\n", stderr);
			break;
	}
	return (1);
}
