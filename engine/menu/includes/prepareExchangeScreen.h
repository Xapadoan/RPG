#ifndef DEF_PREPARE_EXCHANGE_SCREEN
#define DEF_PREPARE_EXCHANGE_SCREEN

#include "../../../includes/config/map_item.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

#include "../../map/includes/Map.h"
#include "../../display/includes/applyRGBA.h"
#include "../../display/includes/blitOnCenter.h"

SDL_Surface *prepareExchangeScreen(char *container_name, SDL_Surface *screen);

#endif
