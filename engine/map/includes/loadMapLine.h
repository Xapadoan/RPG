#ifndef DEF_LOAD_MAP_LINE
#define DEF_LOAD_MAP_LINE

#include "../../../includes/config/map.h"

#include <SDL/SDL.h>

#include "useMapByte.h"

#include "../../../lib/libMY/libMY_int/includes/MY_hex2dec.h"

void	loadMapLine(SDL_Surface *dest, const char *line, SDL_Rect *pos);

#endif
