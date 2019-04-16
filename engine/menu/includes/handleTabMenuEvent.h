#ifndef DEF_HANDLE_TAB_MENU_EVENT
#define DEF_HANDLE_TAB_MENU_EVENT

#include "../../../includes/config/controls.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "TabMenu.h"
#include "getActiveTab.h"
#include "getDisplayTabEntry.h"

int	handleTabMenuEvent(TabMenu *menu, SDL_KeyboardEvent *key, unsigned int *quit);

#endif
