#ifndef DEF_CONFIRM_YESNO
#define DEF_CONFIRM_YESNO

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/font/includes/putFont.h"

int	putYesNo(SDL_Surface *dest, TTF_Font *font, SDL_Color color);

#endif
