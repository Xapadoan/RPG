#ifndef DEF_RESTRICT_MOVEMENTS
#define DEF_RESTRICT_MOVEMENTS

#include <stdlib.h>
#include <SDL/SDL.h>

#include "Hitbox.h"
#include "getCollisionOrigin.h"
#include "checkRectIntersection.h"

#include "../../location/includes/Direction.h"

int	restrictMovements(Hitbox *origin, Hitbox *env, int margin);

/*
 * RETURN VALUE :
 * 		This function return an octal integer representing the direction where
 * 	there are no collisions with a rectangle wraping the 'origin'.
 *
 * COMMON PITFALLS :
 * 	- If the 'env' hitbox is fully contained by the origin hitbox (and vice
 * 		versa), this function will return 15 (allowed to move in every
 * 		direction).
 */

#endif
