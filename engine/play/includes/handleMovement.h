#ifndef DEF_HANDLE_MOVEMENT
#define DEF_HANDLE_MOVEMENT

#include "../../../includes/config/controls.h"

#include "../../character/includes/Team.h"
#include "../../character/includes/changeTeamState.h"
#include "../../map/includes/Map.h"
#include "../../move/includes/go.h"

int	handleMovement(Map *map, Team *team, SDL_KeyboardEvent *event);

#endif
