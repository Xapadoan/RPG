#include "../includes/initMiscItem.h"

MiscItem	*initMiscItem(void)
{
	MiscItem *item;

	item = NULL;
	item = malloc(sizeof(*item));
	if (!item) {
		fputs("Memory Error : Failed to allocate memory for item\n", stderr);
		return (NULL);
	}

	item->id = 0;
	item->name = NULL;
	item->weight = 0;
	item->value = 0;
	item->preview = NULL;
	item->next = NULL;

	return (item);
}
