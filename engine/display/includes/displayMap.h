#ifndef DEF_DISPLAY_MAP
#define DEF_DISPLAY_MAP

#include "screen.h"
#include "map.h"
#include "character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "MY_string.h"
#include "MY_int.h"

#include "Team.h"
#include "Map.h"
#include "initMapBag.h"
#include "deleteMapBag.h"

#include "SpriteList.h"
#include "initSpriteList.h"
#include "deleteSpriteList.h"
#include "displaySpriteList.h"
#include "displayCharacter.h"
#include "displayMapItems.h"
#include "sortGroundItems.h"

int	displayMap(SDL_Surface *screen, Map *map, Team *team);

#endif
