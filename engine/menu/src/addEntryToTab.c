#include "../includes/addEntryToTab.h"

int	addEntryToTab(TabEntry *entry, Tab *tab, unsigned int pos)
{
	unsigned int current_pos;
	TabEntry *current;

	current_pos = 0;
	current = NULL;
	if (!entry | !tab) {
		fputs("Arg Error : Missing arguments for addEntryToTab\n", stderr);
		return (0);
	}

	while (current_pos < pos && current != NULL) {
		current = current->next;
		current_pos++;
	}

	entry->previous = current;
	if (current) {
		entry->next = current->next;
		current->next = entry;
	} else {
		entry->next = NULL;
	}

	if (!tab->first)
		tab->first = entry;

	tab->nb_entries++;
	if (!sortTabDefaultOrder(tab)) {
		fputs("Error : Failed to sort tab with default order\n", stderr);
		return (0);
	}

	return (1);
}
