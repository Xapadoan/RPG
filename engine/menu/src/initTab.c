#include "../includes/initTab.h"

Tab	*initTab(void)
{
	Tab *tab;

	tab = NULL;
	tab = (Tab *)malloc(sizeof(*tab));
	if (!tab) {
		fputs("Memory Error : Failed to allocate memory for tab\n", stderr);
		return (NULL);
	}

	tab->nb_entries = 0;
	tab->id = 0;
	tab->scrollbar = NULL;
	tab->first = NULL;
	tab->current_pos = 0;
	tab->next = NULL;
	tab->previous = NULL;

	return (tab);
}
