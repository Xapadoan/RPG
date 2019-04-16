#ifndef DEF_SHOW_RACE_DESCRIPTION
#define DEF_SHOW_RACE_DESCRIPTION

#include "../../../includes/config/character_menu.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "putRaceInfo.h"

void	showRaceDescription(TTF_Font *font, SDL_Surface *dest, const unsigned int race);

#endif
