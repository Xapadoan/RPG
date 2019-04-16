#ifndef DEF_STAND_UP
#define DEF_STAND_UP

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../character/includes/searchStandUpPos.h"
#include "../../map/includes/Map.h"
#include "Team.h"

int	standUp(Team *team, Map *map, int dir);

#endif
