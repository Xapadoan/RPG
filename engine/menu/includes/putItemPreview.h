#ifndef DEF_PUT_ITEM_PREVIEW
#define DEF_PUT_ITEM_PREVIEW

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "menu.h"
#include "item.h"

#include "item_categories.h"

#include "MY_string.h"
#include "MY_int.h"
#include "MY_convert.h"
#include "MY_array.h"

int	putItemPreview(SDL_Surface *dest, const char *item_str);

#endif
