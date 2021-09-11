#ifndef DEF_CHECK_ALLOWED_MOVES
#define DEF_CHECK_ALLOWED_MOVES

#include "character_hitbox.h"

#include <SDL/SDL.h>

#include "Map.h"
#include "Team.h"
#include "initHitbox.h"
#include "scanIntersection.h"
#include "restrictMovements.h"
#include "deleteHitbox.h"
#include "mergeHitboxes.h"
#include "displayHitbox.h"

int	checkAllowedMoves(Map *map, Team *team, int margin);

#endif
