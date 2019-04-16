#include "../includes/isFacingMapItem.h"

MapItem	*isFacingMapItem(Team *team, Map *map)
{
	MapItem *current;
	SDL_Rect dim;

	current = map->items->first;
	if (!current) {
		fputs("Notice : No items found on map\n", stderr);
		return (NULL);
	}

	while (current != NULL) {
		dim = getHitboxDimensions(current->hitbox);
		if (~restrictMovements(team->hitbox, current->hitbox, MY_MIN(MY_MIN(dim.w, dim.h), MAP_ITEM_MARGIN)) & team->heroes[0].dir)
			return (current);
		current = current->next;
	}

	return (NULL);
}
