#ifndef DEF_HANDLE_ITEM_EXCHANGE_MENU_EVENT
#define DEF_HANDLE_ITEM_EXCHANGE_MENU_EVENT

#include "controls.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "MY_string.h"
#include "MY_convert.h"

#include "TabMenu.h"
#include "Potion.h"
#include "getActiveTab.h"
#include "getDisplayTabEntry.h"

#include "item_categories.h"
#include "ItemBag.h"

#include "Team.h"

#include "Map.h"

int	handleItemExchangeMenuEvent(TabMenu *menu, SDL_KeyboardEvent *key, unsigned int *quit);

#endif
