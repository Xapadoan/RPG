#include "../includes/copyToMapBag.h"

int	copyToMapBag(MapBag *bag, MapItem *item)
{
	MapItem *copy;
	ElemHitbox *elem;

	copy = NULL;
	copy = (MapItem *)malloc(sizeof(*copy));
	if (!copy) {
		fputs("Failed to allocate memory for map item copy\n", stderr);
		return (0);
	}

	initMapItem(copy);
	if (!copy) {
		fputs("Error : Failed to init map item copy\n", stderr);
		return (0);
	}

	copy->sprite = SDL_ConvertSurface(item->sprite, item->sprite->format, MAP_ITEM_SPRITE_FLAGS);
	if (!copy->sprite) {
		fputs("SDL Error : Failed to copy map item sprite\n", stderr);
		deleteMapItem(copy);
		return (0);
	}

	copy->pos.x = item->pos.x;
	copy->pos.y = item->pos.y;
	copy->pos.h = item->pos.h;
	copy->pos.w = item->pos.w;

	if (item->hitbox) {
		copy->hitbox = initHitbox();
		if (!copy->hitbox)
			fputs("Warning : Failed to init copy's hitbox\n", stderr);
		elem = copy->hitbox->first;
		while (elem->next != NULL && copyToHitbox(elem, copy->hitbox))
			elem = elem->next;
	}

	copy->name = MY_str_ncopy(item->name, 0, MY_str_len(item->name));

	copy->action = item->action;
	addToMapBag(bag, copy);
	return (1);
}
