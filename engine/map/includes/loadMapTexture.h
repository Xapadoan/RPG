#ifndef DEF_LOAD_MAP_TEXTURE
#define DEF_LOAD_MAP_TEXTURE

#include "textures_path.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_str_len.h"
#include "MY_str_append.h"

SDL_Surface *loadMapTexture(int tex);

#endif
