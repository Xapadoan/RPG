#ifndef DEF_LOAD_STRUCTURE_SPRITE
#define DEF_LOAD_STRUCTURE_SPRITE

#include "../../../includes/config/struct_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

SDL_Surface *loadStructureSprite(const char *sprite_name, SDL_Rect *pos);

#endif
