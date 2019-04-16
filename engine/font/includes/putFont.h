#ifndef DEF_PUT_FONT
#define DEF_PUT_FONT

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int	putFont(TTF_Font *font, const char *text, SDL_Color color, SDL_Surface *dest, SDL_Rect *pos);

#endif
