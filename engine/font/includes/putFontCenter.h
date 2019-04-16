#ifndef DEF_PUT_FONT_CENTER
#define DEF_PUT_FONT_CENTER

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int	putFontCenter(TTF_Font *font, const char *text, const SDL_Color color, SDL_Surface *dest, SDL_Rect *pos);

#endif
