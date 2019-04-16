#ifndef DEF_PUT_USER_INFO
#define DEF_PUT_USER_INFO

#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/font/includes/putFontColumn.h"

void	putUserInfo(SDL_Surface *dest, TTF_Font *font, const unsigned int choice);

#endif
