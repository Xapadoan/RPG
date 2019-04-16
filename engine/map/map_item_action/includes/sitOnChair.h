#ifndef DEF_SIT_ON_CHAIR
#define DEF_SIT_ON_CHAIR

#include "../../../../includes/config/controls.h"
#include "../../../../includes/config/character_sprite.h"
#include "../../../../includes/config/map_item_sprite_mark.h"
#include "../../../../includes/config/map_item.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "../../../../lib/libMY/libMY_file/includes/MY_go_to_next_line.h"

#include "../../../display/includes/displayMap.h"
#include "../../../character/includes/Team.h"
#include "../../../character/includes/changeTeamState.h"
#include "../../includes/Map.h"
#include "../../includes/openMapItemList.h"
#include "../../includes/searchItemInList.h"
#include "../../../location/includes/Direction.h"

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
