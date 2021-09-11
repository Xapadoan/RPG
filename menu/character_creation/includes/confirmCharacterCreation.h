#ifndef DEF_CONFIRM_CHARACTER_CREATION
#define DEF_CONFIRM_CHARACTER_CREATION

#include "character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Character.h"

#include "prepareConfirmScreen.h"
#include "chooseConfirm.h"

int	confirmCharacterCreation(SDL_Surface *screen, Character *to_confirm);

#endif
