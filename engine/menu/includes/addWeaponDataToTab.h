#ifndef	DEF_ADD_WEAPON_DATA_TO_TAB
#define	DEF_ADD_WEAPON_DATA_TO_TAB

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "MY_string.h"
#include "MY_convert.h"

#include "TabMenu.h"
#include "tab_ids.h"
#include "addEntryToTab.h"
#include "initTabEntry.h"
#include "Weapon.h"
#include "item_categories.h"
#include "loadItemDescription.h"
#include "menu.h"
#include "font.h"
#include "putFont.h"
#include "exchangePotion.h"

int		addWeaponDataToTab(TabMenu *menu, Weapon *weapon);

#endif
