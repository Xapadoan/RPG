#include "printTab.h"

void	printTab(Tab *tab, int flags) {
	TabEntry	*current;

	current = NULL;
	if (!tab) {
		puts("\n--- NO Tab---\n");
		return;
	}

	puts("\n--- Tab ---\n");
	printf("id: %d\tnb entries: %d\tcurrent pos: %d\n", tab->id, tab->nb_entries, tab->current_pos);
	if (flags & 1) {
		current = tab->first;
		while (current) {
			printTabEntry(current, (flags & 2) >> 1);
			current = current->next;
		}
	}
	puts("\n-----------\n");
}
