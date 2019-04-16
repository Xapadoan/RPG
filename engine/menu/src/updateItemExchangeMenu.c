#include "../includes/updateItemExchangeMenu.h"

int updateItemExchangeMenu(TabMenu *menu, MapItem *container)
{
	if (!menu | !container) {
		fputs("Arg Error : Missing arguments for updateItemExchangeMenu\n", stderr);
		return (0);
	}

	if (!putTabMenuBorders(menu)) {
		fputs("Error : Failed to put menu borders\n", stderr);
		return (0);
	}

	if (!updateItemExchangeHeader(menu, container->items, container->name)) {
		fputs("Error : Failed to update header\n", stderr);
		return (0);
	}

	if (!updateItemExchangeTabsPreview(menu)) {
		fputs("Error : Failed to update tabs preview\n", stderr);
		return (0);
	}

	if (!updateTabContent(menu)) {
		fputs("Error : Failed to update tab content\n", stderr);
		return (0);
	}

	return (1);
}
