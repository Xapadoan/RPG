#ifndef DEF_DISPLAY_CHARACTERS
#define DEF_DISPLAY_CHARACTERS

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "MY_int.h"
#include "MY_string.h"

#include "loadCharacterSprite.h"

int	displayCharacter(SDL_Surface *map, Character *character, SDL_Rect *pos, int sprite_id);

#endif
