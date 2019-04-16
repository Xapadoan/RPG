#include "../includes/triggerKeyUp.h"

int	triggerKeyUp(SDL_Surface *screen, Map *map, Team *team, SDL_KeyboardEvent *event)
{
	switch (event->keysym.sym) {
		case (CONTROLS_PAUSE) :
			return (0);
			break;
		case (CONTROLS_ACTION) :
			if (!triggerAction(map, team, screen)) {
				fputs("Error : Trigger map action failed\n", stderr);
				return (0);
			}
			break;
		default :
			break;
	}

	return (1);
}
