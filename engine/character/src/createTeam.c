#include "../includes/createTeam.h"

int	createTeam(SDL_Surface *screen, Team *team)
{
	unsigned int i;

	i = 0;
	if (!team)
		initTeam(team);

	while (i < 4)
		if (!useCharacterCreationMenu(screen, team->heroes, i++)) {
			fputs("Error : Creating character failed\n", stderr);
			return (0);
		}

	team->location.x = 120;
	team->location.y = 140;
	enterMap(team, "tall_town_hall");

	return (1);
}
