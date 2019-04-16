#include "../includes/handlePressedKeys.h"

int	handlePressedKeys(Map *map, Team *team)
{
	int num_keys;
	int dir;
	Uint8 *key_state;

	num_keys = 0;
	dir = 0;
	key_state = SDL_GetKeyState(&num_keys);
	if (!num_keys) {
		return (1);
	}
	if (key_state[CONTROLS_MOVEMENT_LEFT]) {
		dir |= LEFT;
		team->heroes[0].dir = LEFT;
		changeTeamState(team, map, CHARACTER_STATE_WALKING);
	}
	if (key_state[CONTROLS_MOVEMENT_RIGHT]) {
		dir |= RIGHT;
		team->heroes[0].dir = RIGHT;
		changeTeamState(team, map, CHARACTER_STATE_WALKING);
	}
	if (key_state[CONTROLS_MOVEMENT_UP]) {
		dir |= UP;
		team->heroes[0].dir = UP;
		changeTeamState(team, map, CHARACTER_STATE_WALKING);
	}
	if (key_state[CONTROLS_MOVEMENT_DOWN]) {
		dir |= DOWN;
		team->heroes[0].dir = DOWN;
		changeTeamState(team, map, CHARACTER_STATE_WALKING);
	}
	go(map, team, dir);
	return (1);
}
