#ifndef DEF_SCAN_INTERSECTION
#define DEF_SCAN_INTERSECTION

#include <SDL/SDL.h>

#include "Hitbox.h"
#include "checkRectIntersection.h"
#include "copyToHitbox.h"
#include "initHitbox.h"

Hitbox	*scanIntersection(SDL_Rect *area, Hitbox *hitbox);

#endif
