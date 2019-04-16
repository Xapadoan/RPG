#include "../includes/addToMapBag.h"

void	addToMapBag(MapBag *bag, MapItem *item)
{
	if (item != NULL) {
		item->next = bag->first;
		bag->first = item;
		bag->len++;
	}
}
