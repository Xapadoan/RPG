#include "../includes/triggerKeyDown.h"

int	triggerKeyDown(Map *map, Team *team, SDL_KeyboardEvent *event)
{
	puts("OK");
	switch (event->keysym.sym) {
		case (CONTROLS_MOVEMENT_UP) :
		case (CONTROLS_MOVEMENT_DOWN) :
		case (CONTROLS_MOVEMENT_LEFT) :
		case (CONTROLS_MOVEMENT_RIGHT) :
			if (!handleMovement(map, team, event)) {
				fputs(stderr, "Warning : Failed to handle movement\n");
				return (0);
			}
			break;
		default :
			break;
	}

	return (1);
}
