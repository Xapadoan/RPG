#ifndef DEF_SORT_GROUND_ITEMS
#define DEF_SORT_GROUND_ITEMS

#include "character_sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "Map.h"
#include "Team.h"
#include "checkRectIntersection.h"

#include "SpriteList.h"
#include "initSpriteList.h"
#include "addToSpriteList.h"

int	sortGroundItems(MapBag *items, Team *team, SpriteList *foreground);

#endif
