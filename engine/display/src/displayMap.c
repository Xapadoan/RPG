#include "../includes/displayMap.h"

int	displayMap(SDL_Surface *screen, Map *map, Team *team)
{
	SDL_Rect view;
	SDL_Rect pos;
	SpriteList *foreground;

	foreground = NULL;

	//Sets the position of the character
	pos.w = CHARACTER_SPRITE_SIZE_WIDTH;
	pos.h = CHARACTER_SPRITE_SIZE_HEIGHT;
	pos.x = team->location.x;
	pos.y = team->location.y;

	//Sets the center of the camera to the position of the character
	view.w = SCREEN_SIZE_WIDTH;
	view.h = SCREEN_SIZE_HEIGHT;
	view.x = pos.x - (SCREEN_SIZE_WIDTH / 2);
	view.y = pos.y - (SCREEN_SIZE_HEIGHT / 2);

	foreground = initSpriteList();
	if (!foreground) {
		fputs("Error : Failed to initialize foreground\n", stderr);
		return (0);
	}

	if (!map->background) {
		fputs("Error : There is nothing to display\n", stderr);
		return (0);
	}

	//Ajusts the center of the camera if needed
	if (view.x < 0)
		view.x = 0;
	else if (view.x > map->background->w - SCREEN_SIZE_WIDTH)
		view.x = map->background->w - SCREEN_SIZE_WIDTH;

	if (view.y < 0)
		view.y = 0;
	else if (view.y > map->background->h - SCREEN_SIZE_HEIGHT)
		view.y = map->background->h - SCREEN_SIZE_HEIGHT;

	SDL_BlitSurface(map->background, &view, screen, NULL);
	pos.x -= view.x;
	pos.y -= view.y;

	if (!sortGroundItems(map->items, team, foreground))
		fputs("Warning : Failed to sort map items between foreground and background\n", stderr);

	displayMapItems(screen, map->items, &view);


	if ((\
			(team->heroes[0].state == CHARACTER_STATE_RUNNING)\
			|| (team->heroes[0].state == CHARACTER_STATE_WALKING)\
		) && (\
			((team->heroes[0].dir & (UP | DOWN)) && !MY_is_pair(team->location.y / (2 * team->heroes[0].mov_speed)))\
			|| ((team->heroes[0].dir & (LEFT | RIGHT)) && !MY_is_pair(team->location.x / (2 * team->heroes[0].mov_speed)))\
		)) {
		if (\
				(team->heroes[0].dir & (LEFT | RIGHT) && !MY_is_pair(team->location.x / (4 * team->heroes[0].mov_speed)))\
				|| (team->heroes[0].dir & (UP | DOWN))\
				 ) {
			if (!displayCharacter(screen, &(team->heroes[0]), &pos, 2)) {
				fputs("Character Displaying Error\n", stderr);
				return (0);
			}
		} else {
			if (!displayCharacter(screen, &(team->heroes[0]), &pos, 3)) {
				fputs("Error : Can't display third character sprite\n", stderr);
				return (0);
			}
		}
	} else {
		if (!displayCharacter(screen, &(team->heroes[0]), &pos, 1)) {
			fputs("Character Displaying Error\n", stderr);
			return (0);
		}
	}

	if (foreground)
		displaySpriteList(screen, foreground, &view);

	if (!deleteSpriteList(foreground))
		fputs("Warning : Failed to delete map bag (foreground)\n", stderr);

	return (1);
}
