#ifndef DEF_USE_MAP_BYTE
#define DEF_USE_MAP_BYTE

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../../lib/libMY/libMY_int/includes/MY_hex2dec.h"

#include "loadMapTexture.h"
#include "../../display/includes/fillRect.h"

void	useMapByte(SDL_Surface *dest, const char *byte, SDL_Rect *pos);

#endif
