#include "../includes/maxCureTeam.h"

int	maxCureTeam(Team *team)
{
	int i;

	i = 0;
	if (!team) {
		fputs("Error : No team provided\n", stderr);
		return (0);
	}

	while (i < 4) {
		team->heroes[i].health = team->heroes[i].max_health;
		team->heroes[i].stamina = team->heroes[i].max_stamina;
		team->heroes[i].cmbt_state = CHARACTER_CMBT_STATE_NORMAL;
		i++;
	}

	return (1);
}
