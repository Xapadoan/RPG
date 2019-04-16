#include "../includes/deleteMap.h"

void	deleteMap(Map *map)
{
	SDL_FreeSurface(map->background);
	if (!deleteHitbox(map->hitbox))
		fputs("Warning : Failed to delete map hitbox\n", stderr);
	if (!deleteMapBag(map->items))
		fputs("Warning : Failed to delete map items\n", stderr);
}
