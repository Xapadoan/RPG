#ifndef DEF_HANDLE_MOVEMENT
#define DEF_HANDLE_MOVEMENT

#include "controls.h"

#include "Team.h"
#include "changeTeamState.h"
#include "Map.h"
#include "go.h"

int	handleMovement(Map *map, Team *team, SDL_KeyboardEvent *event);

#endif
