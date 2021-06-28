#ifndef DEF_LOAD_CHARACTER_SPRITE
#define DEF_LOAD_CHARACTER_SPRITE

#include "character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_str_len.h"
#include "MY_str_append.h"
#include "MY_replace_char.h"

#include "Direction.h"

#include "Character.h"
#include "Race.h"

int	loadCharacterSprite(Character *character);

#endif
