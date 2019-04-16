#ifndef DEF_DRAW_BRESENHAM_CIRCLE
#define DEF_DRAW_BRESENHAM_CIRCLE

#include <stdio.h>
#include <SDL/SDL.h>

#include "../../../lib/libMY/libMY_int/includes/MY_abs.h"

#include "putPixel.h"
#include "circle_portions.h"

int	drawBresenhamCircle(SDL_Surface *dest, SDL_Rect *origin, unsigned int r, SDL_Color *color, unsigned int flags);

#endif
