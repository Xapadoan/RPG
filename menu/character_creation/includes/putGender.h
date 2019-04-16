#ifndef DEF_PUT_GENDER
#define DEF_PUT_GENDER

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/font/includes/putFont.h"

int	putGender(SDL_Surface *dest, TTF_Font *font, const int gender, SDL_Rect *pos);

#endif
