#ifndef DEF_SEARCH_STAND_UP_POS
#define DEF_SEARCH_STAND_UP_POS

#include "getHitboxDimensions.h"
#include "Direction.h"
#include "Map.h"
#include "checkAllowedMoves.h"
#include "Character.h"
#include "updateTeam.h"

int	searchStandUpPos(Team *team, Map *map, int dir);

#endif
