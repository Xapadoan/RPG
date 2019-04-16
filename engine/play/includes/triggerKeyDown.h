#ifndef DEF_TRIGGER_KEY_DOWN
#define DEF_TRIGGER_KEY_DOWN

#include "../../../includes/config/controls.h"

#include <SDL/SDL.h>

#include "../../character/includes/Team.h"
#include "../../location/includes/Direction.h"
#include "../../map/includes/Map.h"
#include "../../move/includes/go.h"
#include "handleMovements.h"

int	triggerKeyDown(Map *map, Team *team, SDL_KeyboardEvent *event);

#endif
