#ifndef DEF_WRITE_NAME
#define DEF_WRITE_NAME

#include "font.h"
#include "character_menu.h"
#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "MY_string.h"

#include "putFont.h"

int	writeName(SDL_Surface *dest, char *name);
void	addLetter(char *name, unsigned int *lengthName, SDL_KeyboardEvent *key);

#endif
