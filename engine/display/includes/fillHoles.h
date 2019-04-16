#ifndef DEF_FILL_HOLES
#define DEF_FILL_HOLES

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "putPixel.h"

int	fillHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width);
int	fillXHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width);
int	fillYHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width);

#endif
