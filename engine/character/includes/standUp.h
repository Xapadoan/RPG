#ifndef DEF_STAND_UP
#define DEF_STAND_UP

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "searchStandUpPos.h"
#include "Map.h"
#include "Team.h"

int	standUp(Team *team, Map *map, int dir);

#endif
