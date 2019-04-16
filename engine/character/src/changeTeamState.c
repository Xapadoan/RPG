#include "../includes/changeTeamState.h"
#include <stdio.h>

void	changeTeamState(Team *team, Map *map, unsigned int state)
{
	int i;

	i = 0;
	while (i < 4) {
		//If character is sitted
		if (team->heroes[i].state == CHARACTER_STATE_SITTED\
				&& (\
					(state == CHARACTER_STATE_STANDING)\
					|| (state == CHARACTER_STATE_WALKING)\
					|| (state == CHARACTER_STATE_RUNNING)\
				)\
			) {
			if (standUp(team, map, team->heroes[0].dir)) {
				team->heroes[i].state = state;
				team->heroes[i].state_changed = 1;
			}
		} else {
			team->heroes[i].state = state;
			team->heroes[i].state_changed = 1;
		}
		i++;
	}
}
