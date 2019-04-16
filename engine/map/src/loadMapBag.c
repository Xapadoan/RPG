#include "../includes/loadMapBag.h"

int	loadMapBag(MapBag *bag, const char *map_name)
{
	FILE *file;
	MapItem *item;

	file = NULL;
	item = NULL;

	file = openMapItemList(map_name);
	if (!file) {
		fprintf(stderr, "Error : Failed to open map item list (\"%s\")\n", map_name);
		return (0);
	}

	do {
		item = loadMapItem(file, map_name);
		addToMapBag(bag, item);
	} while (item != NULL);

	fclose(file);
	return (1);
}
