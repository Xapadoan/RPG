#include "../includes/deleteMapItem.h"

int	deleteMapItem(MapItem *item)
{
	SDL_FreeSurface(item->sprite);
	if (!deleteHitbox(item->hitbox)) {
		fputs("Error : Failed to delete item hitbox\n", stderr);
		return (0);
	}

	deleteItemBag(item->items);

	free(item->name);
	item->next = NULL;
	free(item);
	return (1);
}
