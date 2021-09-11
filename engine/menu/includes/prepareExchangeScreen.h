#ifndef DEF_PREPARE_EXCHANGE_SCREEN
#define DEF_PREPARE_EXCHANGE_SCREEN

#include "map_item.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_string.h"
#include "MY_convert.h"

#include "Map.h"
#include "applyRGBA.h"
#include "blitOnCenter.h"

SDL_Surface *prepareExchangeScreen(char *container_name, SDL_Surface *screen);

#endif
