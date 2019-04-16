#include "../includes/initMapBag.h"

MapBag	*initMapBag(void)
{
	MapBag *bag;
	MapItem *item;

	bag = NULL;
	item = NULL;

	bag = malloc(sizeof(*bag));
	item = malloc(sizeof(*item));

	if (!bag || !item) {
		fputs("Memory Error : Failed to allocate memory for map items\n", stderr);
		return (NULL);
	}

	initMapItem(item);
	item->next = NULL;
	bag->first = item;
	bag->len = 1;
	return (bag);
}
