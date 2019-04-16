#ifndef DEF_SORT_GROUND_ITEMS
#define DEF_SORT_GROUND_ITEMS

#include "../../../includes/config/character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "../../map/includes/Map.h"
#include "../../character/includes/Team.h"
#include "../../hitbox/includes/checkRectIntersection.h"

#include "SpriteList.h"
#include "initSpriteList.h"
#include "addToSpriteList.h"

int	sortGroundItems(MapBag *items, Team *team, SpriteList *foreground);

#endif
