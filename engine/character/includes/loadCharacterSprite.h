#ifndef DEF_LOAD_CHARACTER_SPRITE
#define DEF_LOAD_CHARACTER_SPRITE

#include "../../../includes/config/character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../lib/libMY/libMY_string/includes/MY_replace_char.h"

#include "../../location/includes/Direction.h"

#include "Character.h"
#include "Race.h"

int	loadCharacterSprite(Character *character);

#endif
