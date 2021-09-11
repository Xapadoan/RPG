#ifndef DEF_PUT_CHARACTER_PREVIEW
#define DEF_PUT_CHARACTER_PREVIEW

#include "character_sprite.h"
#include "character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "Character.h"
#include "Race.h"
#include "putFont.h"

#include "MY_string.h"

int	putCharacterPreview(SDL_Surface *dest, TTF_Font *font, Character *character, SDL_Rect *pos);

#endif
