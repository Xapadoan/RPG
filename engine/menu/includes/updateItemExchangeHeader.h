#ifndef DEF_UPDATE_ITEM_EXCHANGE_HEADER
#define DEF_UPDATE_ITEM_EXCHANGE_HEADER

#include "menu.h"
#include "font.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "MY_string.h"
#include "MY_convert.h"

#include "TabMenu.h"
#include "putTabMenuHeaderBackground.h"
#include "ItemBag.h"
#include "putFont.h"

int	updateItemExchangeHeader(TabMenu *menu, ItemBag *bag, const char *name);

#endif
