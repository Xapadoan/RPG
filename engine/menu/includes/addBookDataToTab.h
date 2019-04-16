#ifndef	DEF_ADD_BOOK_DATA_TO_TAB
#define	DEF_ADD_BOOK_DATA_TO_TAB

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "MY_str_len.h"
#include "MY_str_append.h"
#include "MY_hex2char.h"
#include "MY_dec2str.h"

#include "TabMenu.h"
#include "tab_ids.h"
#include "addEntryToTab.h"
#include "initTabEntry.h"
#include "Book.h"
#include "item_categories.h"
#include "loadItemDescription.h"
#include "menu.h"
#include "font.h"
#include "putFont.h"

int		addBookDataToTab(TabMenu *menu, Book *book);

#endif
