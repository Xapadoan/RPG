#include "../includes/deleteTeam.h"

void	deleteTeam(Team *team)
{
	unsigned int i;

	i = 0;
	while (i < 4)
		deleteCharacter(&(team->heroes[i++]));

	deleteLocation(&(team->location));
	deleteHitbox(team->hitbox);
	deleteItemBag(team->bag);
}
