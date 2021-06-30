#ifndef DEF_LOAD_MAP_LINE
#define DEF_LOAD_MAP_LINE

#include "map.h"

#include <SDL/SDL.h>

#include "useMapByte.h"

#include "MY_hex2dec.h"

void	loadMapLine(SDL_Surface *dest, const char *line, SDL_Rect *pos);

#endif
