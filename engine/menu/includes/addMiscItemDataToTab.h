#ifndef DEF_ADD_MISC_ITEM_DATA_TO_TAB
#define DEF_ADD_MISC_ITEM_DATA_TO_TAB

#include <stdio.h>
#include <stdlib.h>

#include "TabMenu.h"
#include "MiscItem.h"
#include "initTabEntry.h"
#include "tab_ids.h"
#include "menu.h"
#include "MY_str_len.h"
#include "MY_dec2str.h"
#include "MY_hex2char.h"
#include "loadItemDescription.h"
#include "addEntryToTab.h"
#include "putFont.h"
#include "item_categories.h"

int	addMiscItemDataToTab(TabMenu *menu, MiscItem *misc);

#endif
