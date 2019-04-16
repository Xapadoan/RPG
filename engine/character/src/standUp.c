#include "../includes/standUp.h"

int	standUp(Team *team, Map *map, int dir)
{
	int i;

	i = 0;

	if (!searchStandUpPos(team, map, dir))
		fputs("Warning : Failed to find available position for standing up\n", stderr);

	while (i < 4) {
		team->heroes[i].state = CHARACTER_STATE_WALKING;
		team->heroes[i++].state_changed = 1;
	}

	return (1);
}
