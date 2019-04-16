#include "../includes/initMapItem.h"

void	initMapItem(MapItem *item)
{
	item->id = 0;
	item->sprite = NULL;
	item->pos.x = 0;
	item->pos.y = 0;
	item->pos.w = 0;
	item->pos.h = 0;
	item->hitbox = initHitbox();
	item->name = NULL;
	item->action = NULL;
	item->next = NULL;
	item->items = initItemBag();
}
