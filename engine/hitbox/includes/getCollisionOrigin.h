#ifndef DEF_GET_COLLISION_ORIGIN
#define DEF_GET_COLLISION_ORIGIN

#include <SDL/SDL.h>

#include "Direction.h"
#include "isInRect.h"

int	getCollisionOrigin(SDL_Rect *origin, SDL_Rect *other, int margin);

#endif
