#ifndef DEF_PUT_ITEM_PREVIEW
#define DEF_PUT_ITEM_PREVIEW

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../includes/config/menu.h"
#include "../../../includes/config/item.h"

#include "../../item/includes/item_categories.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_split.h"

#include "../../../lib/libMY/libMY_int/includes/MY_pow.h"
#include "../../../lib/libMY/libMY_int/includes/MY_str2hex.h"

#include "../../../lib/libMY/libMY_array/includes/MY_free_2d_char.h"

int	putItemPreview(SDL_Surface *dest, const char *item_str);

#endif
