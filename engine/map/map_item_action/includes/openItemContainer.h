#ifndef DEF_OPEN_ITEM_CONTAINER
#define DEF_OPEN_ITEM_CONTAINER

#include <SDL/SDL.h>

#include "Team.h"
#include "Map.h"
#include "prepareExchangeScreen.h"
#include "TabMenu.h"
#include "initTabMenu.h"
#include "deleteTabMenu.h"
#include "setTabMenuHeight.h"
#include "setTabMenuWidth.h"
#include "setTabMenuHeaderHeight.h"
#include "setTabsPreviewHeight.h"
#include "updateItemExchangeMenu.h"
#include "createItemExchangeTabs.h"
#include "loadItemExchangeMenuContent.h"
#include "handleTabMenuEvent.h"

int	openItemContainer(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv);

#endif
