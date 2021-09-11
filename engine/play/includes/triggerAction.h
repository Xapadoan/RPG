#ifndef DEF_TRIGGER_ACTION
#define DEF_TRIGGER_ACTION

#include <stdlib.h>
#include <SDL/SDL.h>

#include "Map.h"
#include "Team.h"
#include "isFacingMapItem.h"

int	triggerAction(Map *map, Team *team, SDL_Surface *screen);

#endif
