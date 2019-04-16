#ifndef DEF_LOAD_MAP_TEXTURE
#define DEF_LOAD_MAP_TEXTURE

#include "../../../includes/config/textures_path.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

SDL_Surface *loadMapTexture(int tex);

#endif
