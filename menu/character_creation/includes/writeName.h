#ifndef DEF_WRITE_NAME
#define DEF_WRITE_NAME

#include "../../../includes/config/font.h"
#include "../../../includes/config/character_menu.h"
#include "../../../includes/config/character.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "../../../lib/libMY/libMY_string/includes/MY_str_len.h"

#include "../../../engine/font/includes/putFont.h"

int	writeName(SDL_Surface *dest, char *name);
void	addLetter(char *name, unsigned int *lengthName, SDL_KeyboardEvent *key);

#endif
