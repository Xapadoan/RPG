#ifndef DEF_LOAD_ITEM_DESCRIPTION
#define DEF_LOAD_ITEM_DESCRIPTION

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../includes/config/menu.h"
#include "../../../includes/config/font.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_split.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_capitalize.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_ncopy.h"
#include "../../../lib/libMY/libMY_string/includes/MY_replace_char.h"
#include "../../../lib/libMY/libMY_array/includes/MY_free_2d_char.h"

#include "TabMenu.h"
#include "putItemPreview.h"

#include "../../font/includes/putFontCenter.h"

int			loadItemDescription(TabEntry *self, TabMenu *menu);

#endif
