#ifndef DEF_SIT_ON_CHAIR
#define DEF_SIT_ON_CHAIR

#include "controls.h"
#include "character_sprite.h"
#include "map_item_sprite_mark.h"
#include "map_item.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "MY_go_to_next_line.h"

#include "displayMap.h"
#include "Team.h"
#include "changeTeamState.h"
#include "Map.h"
#include "openMapItemList.h"
#include "searchItemInList.h"
#include "Direction.h"

int	sitOnChair(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv);
int	loadSittedSprite(Character *character, MapItem *chair);

/*
 * DESCRIPTION :
 * 	This function creates a sprite of the character sitted on the chair he is
 * 		interacting with (just sitted if no chair), and sets it as character
 * 		sprite.
 * 
 * RETURN VALUE :
 * 	This function returns 1 if everything is ok and 0 on error
 */

#endif
