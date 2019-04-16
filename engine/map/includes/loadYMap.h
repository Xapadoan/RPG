#ifndef DEF_LOAD_YMAP
#define DEF_LOAD_YMAP

#include "../../../includes/config/map.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "loadMapLine.h"

SDL_Surface *loadYMap(const char *map_path);
SDL_Rect getMapDimensions(FILE *map_file);

#endif
