#ifndef DEF_TRIGGER_ACTION
#define DEF_TRIGGER_ACTION

#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../map/includes/Map.h"
#include "../../character/includes/Team.h"
#include "../../character/includes/isFacingMapItem.h"

int	triggerAction(Map *map, Team *team, SDL_Surface *screen);

#endif
