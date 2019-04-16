#ifndef DEF_SEARCH_STAND_UP_POS
#define DEF_SEARCH_STAND_UP_POS

#include "../../hitbox/includes/getHitboxDimensions.h"
#include "../../location/includes/Direction.h"
#include "../../map/includes/Map.h"
#include "../../move/includes/checkAllowedMoves.h"
#include "Character.h"
#include "updateTeam.h"

int	searchStandUpPos(Team *team, Map *map, int dir);

#endif
