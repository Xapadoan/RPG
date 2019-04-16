#ifndef DEF_LOAD_TAB_PREVIEW_ICON
#define DEF_LOAD_TAB_PREVIEW_ICON

#include "../../../includes/config/menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

SDL_Surface	*loadTabPreviewIcon(const char *name);

#endif
