#include "../includes/deleteTabList.h"

void	deleteTabList(TabList *list)
{
	Tab *current;

	current = NULL;
	if (list->first) {
		current = list->first;
		while (current) {
			list->first = current->next;
			deleteTab(current);
			current = list->first;
		}

		list->first = NULL;
	}

	free(list);
	list = NULL;
}
