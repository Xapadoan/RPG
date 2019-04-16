#ifndef DEF_PUT_FONT_COLUMN
#define DEF_PUT_FONT_COLUMN

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "putFont.h"

#include "../../../lib/libMY/libMY_string/includes/MY_clear_string.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"
#include "../../../lib/libMY/libMY_string/includes/MY_str_append.h"

void	putFontColumn(TTF_Font *font, const char *text, const SDL_Color color, SDL_Surface *dest, SDL_Rect *pos, const int length);

#endif
