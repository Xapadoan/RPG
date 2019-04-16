#include "../includes/initTabList.h"

TabList	*initTabList(void) {
	TabList *list;

	list = NULL;

	list = (TabList *)malloc(sizeof(*list));
	if (!list) {
		fputs("Memory Error : Failed to allocate memory for tab list\n", stderr);
		return (NULL);
	}

	list->nb_tabs = 0;
	list->first = NULL;

	return (list);
}
