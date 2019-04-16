#include "loadMiscItemTab.h"

int	loadMiscItemTab(TabMenu *menu, MiscBag *misc_items) {
	MiscItem *misc_item;

	misc_item = NULL;
	if (!menu | !misc_items) {
		fputs("Error : Missing arguments for load MiscItem Tab\n", stderr);
		return (0);
	}

	if (!menu->tabs) {
		fputs("Error : Menu tab list are not initialized\n", stderr);
		return (0);
	}

	misc_item = misc_items->first;
	while (misc_item->next) {
		if (!addMiscItemDataToTab(menu, misc_item)) {
			fputs("Error : Failed to add misc_item data to tab\n", stderr);
			return (0);
		}
		misc_item = misc_item->next;
	}

	return (1);
}
