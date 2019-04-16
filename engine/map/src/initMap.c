#include "../includes/initMap.h"

int	initMap(Map *map)
{
	map->background = NULL;
	map->items = initMapBag();
	if (!map->items) {
		fputs("Error : Failed to init map items\n", stderr);
		return (0);
	}
	map->hitbox = initHitbox();
	if (!map->hitbox) {
		fputs("Error : Failed to init map hitbox\n", stderr);
		return (0);
	}

	return (1);
}
