#ifndef DEF_ADD_POTION_DATA_TO_TAB
#define DEF_ADD_POTION_DATA_TO_TAB

#include "menu.h"
#include "font.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "MY_string.h"
#include "MY_convert.h"

#include "item_categories.h"

#include "TabMenu.h"
#include "initTabEntry.h"
#include "addEntryToTab.h"
#include "loadItemDescription.h"
#include "exchangePotion.h"
#include "Potion.h"
#include "putFont.h"

#include "FnctPtr.h"

int	addPotionDataToTab(TabMenu *menu, Potion *potion, unsigned int tab_id);
int	setPotionEntrySurface(TabEntry *entry, Potion *potion);

#endif
