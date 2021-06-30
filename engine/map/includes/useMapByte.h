#ifndef DEF_USE_MAP_BYTE
#define DEF_USE_MAP_BYTE

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "MY_hex2dec.h"

#include "loadMapTexture.h"
#include "fillRect.h"

void	useMapByte(SDL_Surface *dest, const char *byte, SDL_Rect *pos);

#endif
