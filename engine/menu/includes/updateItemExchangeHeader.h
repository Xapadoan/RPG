#ifndef DEF_UPDATE_ITEM_EXCHANGE_HEADER
#define DEF_UPDATE_ITEM_EXCHANGE_HEADER

#include "../../../includes/config/menu.h"
#include "../../../includes/config/font.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../lib/libMY/libMY_string/includes/MY_dec2str.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_capitalize.h"

#include "TabMenu.h"
#include "putTabMenuHeaderBackground.h"
#include "../../item/includes/ItemBag.h"
#include "../../font/includes/putFont.h"

int	updateItemExchangeHeader(TabMenu *menu, ItemBag *bag, const char *name);

#endif
