#ifndef DEF_PUT_NAME
#define DEF_PUT_NAME

#include "../../../includes/config/character_menu.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/font/includes/putFont.h"

int	putName(SDL_Surface *dest, TTF_Font *font, const char *name, SDL_Rect *posBox);

#endif
