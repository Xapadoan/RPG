#ifndef DEF_SLEEP
#define DEF_SLEEP

#include "../../../../includes/config/map_item.h"
#include "../../../../includes/config/character_sprite.h"
#include "../../../../includes/config/screen.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../../lib/libMY/libMY_string/includes/MY_str_compare.h"

#include "../../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h"

#include "../../../character/includes/Team.h"
#include "../../../character/includes/updateTeam.h"
#include "../../../character/includes/maxCureTeam.h"
#include "../../../character/includes/putClosedEyes.h"
#include "../../../location/includes/Direction.h"
#include "../../../display/includes/displayMapItems.h"
#include "../../includes/Map.h"
#include "../../includes/openMapItemList.h"

int	sleep(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv);
int	sleepAnimation(MapItem *item, Map *map, Team *team, SDL_Surface *screen);

#endif
