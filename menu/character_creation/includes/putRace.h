#ifndef DEF_PUT_RACE
#define DEF_PUT_RACE

#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/character/includes/Race.h"

#include "../../../engine/font/includes/putFont.h"

int	putRace(SDL_Surface *menu, TTF_Font *font, unsigned int race, SDL_Rect *pos);

#endif
