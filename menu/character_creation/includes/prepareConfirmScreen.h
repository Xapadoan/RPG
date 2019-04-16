#ifndef DEF_PREPARE_CONFIRM_SCREEN
#define DEF_PREPARE_CONFIRM_SCREEN

#include "../../../includes/config/font.h"
#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "../../../engine/font/includes/putFont.h"

#include "putCharacterInfo.h"
#include "putYesNo.h"

SDL_Surface *prepareConfirmScreen(Character *to_confirm);

#endif
