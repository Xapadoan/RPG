#ifndef DEF_LOAD_STRUCTURE_SPRITE
#define DEF_LOAD_STRUCTURE_SPRITE

#include "struct_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_string.h"

SDL_Surface *loadStructureSprite(const char *sprite_name, SDL_Rect *pos);

#endif
