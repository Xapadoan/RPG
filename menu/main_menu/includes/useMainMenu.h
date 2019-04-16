#ifndef DEF_USE_MAIN_MENU
#define DEF_USE_MAIN_MENU

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../../engine/includes/endSDL.h"

#include "putMainChoices.h"
#include "moveMainCursor.h"
#include "putTitleScreen.h"

#define EXIT_MENU() SDL_FreeSurface(menu);\
	SDL_FreeSurface(screen);\
	endSDL();\
	exit(EXIT_SUCCESS);\

int	useMainMenu(SDL_Surface *screen);

#endif
