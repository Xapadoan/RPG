#include "initMiscBag.h"

MiscBag	*initMiscBag(void)
{
	MiscBag *items;
	MiscItem *item;

	item = NULL;
	items = NULL;

	items = malloc(sizeof(*items));
	if (!items) {
		fputs("Memory Error : Failed to allocate memory for item bag\n", stderr);
		return (NULL);
	}

	item = initMiscItem();
	if (!item) {
		fputs("Error : Failed to init item\n", stderr);
		return (NULL);
	}

	items->nb = 0;
	items->weight = 0;
	items->value = 0;
	items->first = item;
	return (items);
}
