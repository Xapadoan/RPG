#include "../includes/initTeam.h"

void	initTeam(Team *team)
{
	unsigned int i;
	SDL_Rect rect;

	i = 0;
	while(i < 4)
		initCharacter(&(team->heroes[i++]));

	if (!initLocation(&(team->location)))
		fputs("Warning : Can't initialise location\n", stderr);
	team->hitbox = initHitbox();
	rect.x = team->location.x - CHARACTER_HITBOX_X / 2;
	rect.y = team->location.y - CHARACTER_HITBOX_Y / 2;
	rect.w = CHARACTER_HITBOX_W;
	rect.h = CHARACTER_HITBOX_H;
	if (!addToHitbox(team->hitbox, &rect))
		fputs("Warning : Can't create character hitbox\n", stderr);
	team->bag = initItemBag();
}
