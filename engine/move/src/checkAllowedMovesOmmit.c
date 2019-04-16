#include "../includes/checkAllowedMovesOmmit.h"

int	checkAllowedMovesOmmit(Map *map, Team *team, int margin, MapItem *item)
{
	int allowed;
	Hitbox *env;
	Hitbox *items;
	SDL_Rect limit;
	MapItem *current_item;

	allowed = 0;
	items = NULL;
	current_item = map->items->first;
	limit.x = team->location.x - margin;
	limit.y = team->location.y - margin;
	limit.w = 2 * margin;
	limit.h = 2 * margin;
	env = scanIntersection(&limit, map->hitbox);
	while (current_item != NULL) {
		if (current_item->hitbox && current_item != item) {
			items = scanIntersection(&limit, current_item->hitbox);
			env = mergeHitboxes(env, items);
		}
		current_item = current_item->next;
		deleteHitbox(items);
		items = NULL;
	}

	allowed = restrictMovements(team->hitbox, env, margin);

	deleteHitbox(env);
	return (allowed);
}
