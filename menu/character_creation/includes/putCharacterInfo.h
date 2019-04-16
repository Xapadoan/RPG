#ifndef DEF_PUT_CHARACTER_INFO
#define DEF_PUT_CHARACTER_INFO

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/font/includes/putFont.h"

#include "../../../engine/character/includes/Character.h"
#include "../../../engine/character/includes/Race.h"

int	putCharacterInfo(SDL_Surface *dest, Character *to_display, TTF_Font *font, SDL_Color color, SDL_Rect *pos);

#endif
