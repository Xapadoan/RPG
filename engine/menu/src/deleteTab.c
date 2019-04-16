#include "../includes/deleteTab.h"

void	deleteTab(Tab *tab)
{
	TabEntry *current;

	current = NULL;
	if (tab->first\
			&& !(tab->id == ALL_TAB_ID)) {
		current = tab->first;
		while (current) {
			tab->first = current->next;
			deleteTabEntry(current);
			current = tab->first;
		}
	}

	if (tab->scrollbar)
		SDL_FreeSurface(tab->scrollbar);

	if (tab->previous)
		tab->previous->next = tab->next;

	if (tab->next)
		tab->next->previous = tab->previous;

	tab->previous = NULL;
	tab->next = NULL;

	free(tab);
	tab = NULL;
}
