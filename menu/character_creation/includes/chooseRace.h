#ifndef DEF_CHOOSE_RACE
#define DEF_CHOOSE_RACE

#include "../../../includes/config/character_menu.h"
#include "../../../includes/config/font.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "showRaceDescription.h"
#include "useRaceMenu.h"
#include "putRaces.h"
#include "../../../engine/includes/endSDL.h"

#define FREE_RACE() SDL_FreeSurface(background);\
		SDL_FreeSurface(select);\
		TTF_CloseFont(fontRace);\
		TTF_CloseFont(fontDescribe);

int	chooseRace(SDL_Surface *screen, unsigned int *race);

#endif
