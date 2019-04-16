#ifndef DEF_ADD_POTION_DATA_TO_TAB
#define DEF_ADD_POTION_DATA_TO_TAB

#include "../../../includes/config/menu.h"
#include "../../../includes/config/font.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../lib/libMY/libMY_string/includes/MY_dec2str.h"

#include "../../../lib/libMY/libMY_int/includes/MY_hex2char.h"

#include "tab_ids.h"
#include "../../item/includes/item_categories.h"

#include "TabMenu.h"
#include "initTabEntry.h"
#include "addEntryToTab.h"
#include "loadItemDescription.h"
#include "../../item/includes/Potion.h"
#include "../../font/includes/putFont.h"

#include "../../includes/FnctPtr.h"

int	addPotionDataToTab(TabMenu *menu, Potion *potion);
int	setPotionEntrySurface(TabEntry *entry, Potion *potion);

#endif
