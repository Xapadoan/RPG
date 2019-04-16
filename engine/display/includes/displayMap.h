#ifndef DEF_DISPLAY_MAP
#define DEF_DISPLAY_MAP

#include "../../../includes/config/screen.h"
#include "../../../includes/config/map.h"
#include "../../../includes/config/character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

#include "../../character/includes/Team.h"
#include "../../map/includes/Map.h"
#include "../../map/includes/initMapBag.h"
#include "../../map/includes/deleteMapBag.h"

#include "SpriteList.h"
#include "initSpriteList.h"
#include "deleteSpriteList.h"
#include "displaySpriteList.h"
#include "displayCharacter.h"
#include "displayMapItems.h"
#include "sortGroundItems.h"

int	displayMap(SDL_Surface *screen, Map *map, Team *team);

#endif
