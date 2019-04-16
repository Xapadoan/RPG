#ifndef DEF_CHECK_ALLOWED_MOVES
#define DEF_CHECK_ALLOWED_MOVES

#include "../../../includes/config/character_hitbox.h"

#include <SDL/SDL.h>

#include "../../map/includes/Map.h"
#include "../../character/includes/Team.h"
#include "../../hitbox/includes/initHitbox.h"
#include "../../hitbox/includes/scanIntersection.h"
#include "../../hitbox/includes/restrictMovements.h"
#include "../../hitbox/includes/deleteHitbox.h"
#include "../../hitbox/includes/mergeHitboxes.h"
#include "../../display/includes/displayHitbox.h"

int	checkAllowedMoves(Map *map, Team *team, int margin);

#endif
