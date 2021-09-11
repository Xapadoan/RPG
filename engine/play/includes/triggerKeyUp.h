#ifndef DEF_TRIGGER_KEY_UP
#define DEF_TRIGGER_KEY_UP

#include "controls.h"

#include <SDL/SDL.h>

#include "Map.h"
#include "Team.h"

#include "triggerAction.h"

int	triggerKeyUp(SDL_Surface *screen, Map *map, Team *team, SDL_KeyboardEvent *event);

#endif
