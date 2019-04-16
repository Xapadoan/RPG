#include "../includes/getActiveTab.h"

Tab	*getActiveTab(TabMenu *menu) {
	Tab *active_tab;

	active_tab = NULL;
	if (!menu) {
		fputs("Arg Error : Missing arguments for getActiveTab\n", stderr);
		return (NULL);
	}

	if (!menu->tabs | !menu->tabs->first) {
		fputs("Warning : Provided menu has no tabs\n", stderr);
		return (NULL);
	}

	active_tab = menu->tabs->first;
	while (active_tab != NULL && active_tab->id != menu->active_tab)
		active_tab = active_tab->next;

	return (active_tab);
}
