#ifndef DEF_MOVE_MAIN_CURSOR
#define DEF_MOVE_MAIN_CURSOR

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "putMainChoices.h"

#include "endSDL.h"

#include "interface_sprite.h"

int	moveMainCursor(SDL_Surface *menu, SDL_Surface *screen, int *choice);
int	testPosMainCursor(SDL_Surface *menu, SDL_Rect *pos);

#endif
