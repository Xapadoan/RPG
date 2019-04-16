#include "../includes/checkAllowedMoves.h"

int	checkAllowedMoves(Map *map, Team *team, int margin)
{
	int allowed;
	Hitbox *env;
	Hitbox *items;
	SDL_Rect limit;
	MapItem *current_item;

	allowed = 0;
	items = NULL;	//This hitbox will be initialized in scanIntersection
	current_item = map->items->first;
	limit.x = team->location.x - CHARACTER_HITBOX_CHECK_WIDTH / 2;
	limit.y = team->location.y - CHARACTER_HITBOX_CHECK_HEIGHT / 2;
	limit.w = CHARACTER_HITBOX_CHECK_WIDTH;
	limit.h = CHARACTER_HITBOX_CHECK_HEIGHT;
	env = scanIntersection(&limit, map->hitbox);
	while (current_item != NULL && current_item->next != NULL) {
		if (current_item->hitbox) {
			items = scanIntersection(&limit, current_item->hitbox);
			env = mergeHitboxes(env, items);
		}
		current_item = current_item->next;
		deleteHitbox(items);
	}

	displayHitbox(map->background, env);
	displayHitbox(map->background, team->hitbox);

	allowed = restrictMovements(team->hitbox, env, margin);

	deleteHitbox(env);
	return (allowed);
}
