#include "../includes/getDisplayTabEntry.h"

TabEntry	*getDisplayTabEntry(Tab *tab, unsigned int display_id) {
	TabEntry *entry;

	entry = NULL;
	if (!tab) {
		fputs("Argv Error : Missing arguments for getDisplayTabEntry\n", stderr);
		return (NULL);
	}

	if (!tab->first)
		return (NULL);

	entry = tab->first;
	while (entry != NULL && entry->display_pos != display_id)
		entry = entry->next;

	return (entry);
}
