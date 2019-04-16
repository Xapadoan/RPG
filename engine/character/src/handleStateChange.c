#include "../includes/handleStateChange.h"

int	handleStateChange(Team *team)
{
	int i;

	i = 0;

	while (i < 4) {
		if (team->heroes[i].state_changed) {
			updateTeam(team);
			team->heroes[i].state_changed = 0;
		}

		i++;
	}

	return (1);
}
