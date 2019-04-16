#include "../includes/updateTeam.h"

void	updateTeam(Team *team)
{
	team->hitbox->first->pos.x = team->location.x + CHARACTER_HITBOX_X;
	team->hitbox->first->pos.y = team->location.y + CHARACTER_HITBOX_Y;
	if (!loadCharacterSprite(&(team->heroes[0])))
		fputs("Warning : Failed to update character sprite\n", stderr);
}
