#ifndef DEF_HANDLE_PRESSED_KEYS
#define DEF_HANDLE_PRESSED_KEYS

#include "../../../includes/config/controls.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include "../../character/includes/Team.h"
#include "../../character/includes/changeTeamState.h"
#include "../../location/includes/Direction.h"
#include "../../map/includes/Map.h"

#include "go.h"

int handlePressedKeys(Map *map, Team *team);

#endif
