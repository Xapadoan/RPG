#ifndef DEF_USE_RACE_MENU
#define DEF_USE_RACE_MENU

#include "../../../includes/config/character_menu.h"

#include <SDL/SDL.h>

#define RACE_MENU_LIMIT_UP (2 * CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_RACE_HEIGHT)

int	useRaceMenu(SDL_Rect *pos, unsigned int *race, SDL_KeyboardEvent *key);

#endif
