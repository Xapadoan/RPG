#ifndef DEF_TRIGGER_KEY_DOWN
#define DEF_TRIGGER_KEY_DOWN

#include "controls.h"

#include <SDL/SDL.h>

#include "Team.h"
#include "Direction.h"
#include "Map.h"
#include "go.h"
#include "handleMovement.h"

int	triggerKeyDown(Map *map, Team *team, SDL_KeyboardEvent *event);

#endif
