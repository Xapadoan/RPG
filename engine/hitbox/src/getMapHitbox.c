#include "../includes/getMapHitbox.h"

Hitbox	*getMapHitbox(Map *map)
{
	Hitbox *map_hitbox;
	MapItem *current;

	map_hitbox = initHitbox();
	if (!map->hitbox)
		fputs("Warning : There is no map hitbox\n", stderr);
	map_hitbox = mergeHitboxes(map_hitbox, map->hitbox);

	if (!map->items || !map->items->first) {
		fputs("Warning : There is no map items\n", stderr);
		return (map_hitbox);
	}

	current = map->items->first;
	while (current != NULL) {
		map_hitbox = mergeHitboxes(map_hitbox, current->hitbox);
		current = current->next;
	}

	return (map_hitbox);
}
