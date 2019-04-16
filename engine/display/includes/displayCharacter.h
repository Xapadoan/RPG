#ifndef DEF_DISPLAY_CHARACTERS
#define DEF_DISPLAY_CHARACTERS

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../../lib/libMY/libMY_int/includes/MY_is_pair.h"
#include "../../../lib/libMY/libMY_string/includes/MY_replace_char.h"

#include "../../character/includes/loadCharacterSprite.h"

int	displayCharacter(SDL_Surface *map, Character *character, SDL_Rect *pos, int sprite_id);

#endif
