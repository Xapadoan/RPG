#include "../includes/deleteMapBag.h"

int	deleteMapBag(MapBag *bag)
{
	while (bag->len > 0 && bag->first != NULL)
		if (!deleteFromMapBag(bag, 0)) {
			fputs("Error : Failed to delete bag\n", stderr);
			return (0);
		}
	free(bag);
	return (1);
}
