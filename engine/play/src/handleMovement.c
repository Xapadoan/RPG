#include "../includes/handleMovement.h"

int	handleMovement(Map *map, Team *team, SDL_KeyboardEvent *event)
{
	puts("OK");
	if ((event->keysym.sym | CONTROLS_MOVEMENT_RUN) && (team->heroes[0].state != CHARACTER_STATE_RUNNING))
		changeTeamState(team, map, CHARACTER_STATE_RUNNING);
	switch (event->keysym.sym) {
		case (CONTROLS_MOVEMENT_UP) :
			go(map, team, UP);
			break;
		case (CONTROLS_MOVEMENT_DOWN) :
			go(map, team, DOWN);
			break;
		case (CONTROLS_MOVEMENT_LEFT) :
			go(map, team, LEFT);
			break;
		case (CONTROLS_MOVEMENT_RIGHT) :
			go(map, team, RIGHT);
			break;
		default :
			break;
	}

	return (1);
}
