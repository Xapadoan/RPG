#ifndef DEF_CHECK_ALLOWED_MOVES
#define DEF_CHECK_ALLOWED_MOVES

#include <SDL/SDL.h>

#include "../../map/includes/Map.h"
#include "../../character/includes/Team.h"
#include "../../hitbox/includes/initHitbox.h"
#include "../../hitbox/includes/scanIntersection.h"
#include "../../hitbox/includes/restrictMovements.h"
#include "../../hitbox/includes/deleteHitbox.h"
#include "../../hitbox/includes/mergeHitboxes.h"
#include "../../display/includes/displayHitbox.h"

int	checkAllowedMovesOmmit(Map *map, Team *team, int margin, MapItem *item);

#endif
