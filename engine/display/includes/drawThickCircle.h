#ifndef DEF_DRAW_THICK_CIRCLE
#define DEF_DRAW_THICK_CIRCLE

#include <stdio.h>
#include <SDL/SDL.h>

#include "circle_portions.h"
#include "drawBresenhamCircle.h"
#include "fillHoles.h"

int	drawThickCircle(SDL_Surface *dest, SDL_Rect *origin, unsigned int r, unsigned int thickness, SDL_Color *color, unsigned int flags);

#endif
