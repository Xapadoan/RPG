#include "../includes/sortGroundItems.h"

int	sortGroundItems(MapBag *items, Team *team, SpriteList *foreground)
{
	SDL_Rect character;
	MapItem *current;
	int i;

	i = 0;
	character.x = 0;
	character.y = 0;
	character.h = 0;
	character.w = 0;
	current = NULL;
	if (!team) {
		fputs("Error : There is no team\n", stderr);
		return (0);
	}

	character.x = team->location.x - CHARACTER_SPRITE_SIZE_WIDTH / 2 + CHARACTER_SPRITE_MARGIN_LEFT;
	character.y = team->location.y - CHARACTER_SPRITE_SIZE_HEIGHT / 2 + CHARACTER_SPRITE_MARGIN_TOP;
	character.w = team->heroes[0].sprite->w - (CHARACTER_SPRITE_MARGIN_LEFT + CHARACTER_SPRITE_MARGIN_RIGHT);
	character.h = team->heroes[0].sprite->h - (CHARACTER_SPRITE_MARGIN_TOP + CHARACTER_SPRITE_MARGIN_BOTTOM);

	if (!foreground) {
		foreground = initSpriteList();
		if (!foreground) {
			fputs("Error : Failed to initialize sprite list\n", stderr);
			return (0);
		}
	}

	if (items == NULL)
		return (1);

	current = items->first;
	while (i < items->len && current->next != NULL) {
		if (checkRectIntersection(&character, &(current->pos)))
			if (character.y + character.h < current->pos.y + current->pos.h) {
				addToSpriteList(foreground, current->sprite, current->pos.x, current->pos.y);
			}
		current = current->next;
		i++;
	}

	return (1);
}
