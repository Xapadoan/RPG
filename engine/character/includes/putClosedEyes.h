#ifndef DEF_PUT_CLOSED_EYES
#define DEF_PUT_CLOSED_EYES

#include "../../../includes/config/character_sprite.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Character.h"
#include "Race.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

int	putClosedEyes(Character *character, SDL_Surface *surf, SDL_Rect *character_pos);

#endif
