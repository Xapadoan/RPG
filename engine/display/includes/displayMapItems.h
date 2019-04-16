#ifndef DEF_DISPLAY_MAP_ITEMS
#define DEF_DISPLAY_MAP_ITEMS

#include <stdlib.h>
#include "../../map/includes/Map.h"
#include "../../hitbox/includes/isInRect.h"

void	displayMapItems(SDL_Surface *dest, MapBag *bag, SDL_Rect *view);

#endif
