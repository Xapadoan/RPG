#ifndef DEF_SLEEP
#define DEF_SLEEP

#include "map_item.h"
#include "character_sprite.h"
#include "screen.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_string.h"
#include "MY_file.h"

#include "Team.h"
#include "updateTeam.h"
#include "maxCureTeam.h"
#include "putClosedEyes.h"
#include "Direction.h"
#include "displayMapItems.h"
#include "Map.h"
#include "openMapItemList.h"
#include "searchItemInList.h"

int	sleepInBed(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv);
int	sleepAnimation(MapItem *item, Map *map, Team *team, SDL_Surface *screen);

#endif
