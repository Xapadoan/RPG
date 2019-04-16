#include "../includes/triggerAction.h"

int	triggerAction(Map *map, Team *team, SDL_Surface *screen)
{
	MapItem *item;

	item = NULL;
	item = isFacingMapItem(team, map);
	if (item && item->action) {
		if (!item->action(item, map, team, screen, NULL)) {
			fputs("Error : Action failed\n", stderr);
			return (0);
		}
	}

	return (1);
}
