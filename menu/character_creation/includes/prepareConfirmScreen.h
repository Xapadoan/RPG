#ifndef DEF_PREPARE_CONFIRM_SCREEN
#define DEF_PREPARE_CONFIRM_SCREEN

#include "font.h"
#include "character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "putFont.h"

#include "putCharacterInfo.h"
#include "putYesNo.h"

SDL_Surface *prepareConfirmScreen(Character *to_confirm);

#endif
