#ifndef DEF_PUT_CHARACTER_PREVIEW
#define DEF_PUT_CHARACTER_PREVIEW

#include "../../../includes/config/character_sprite.h"
#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/character/includes/Character.h"
#include "../../../engine/character/includes/Race.h"
#include "../../../engine/font/includes/putFont.h"

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"

int	putCharacterPreview(SDL_Surface *dest, TTF_Font *font, Character *character, SDL_Rect *pos);

#endif
