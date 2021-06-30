#ifndef DEF_SLEEP
#define DEF_SLEEP

#include "map_item.h"
#include "character_sprite.h"
#include "screen.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MY_str_len.h"
#include "MY_str_append.h"
#include "MY_str_compare.h"

#include "MY_go_to_next_line.h"

#include "Team.h"
#include "updateTeam.h"
#include "maxCureTeam.h"
#include "putClosedEyes.h"
#include "Direction.h"
#include "displayMapItems.h"
#include "Map.h"
#include "openMapItemList.h"

int	sleep(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv);
int	sleepAnimation(MapItem *item, Map *map, Team *team, SDL_Surface *screen);

#endif
