#ifndef DEF_USE_CHARACTER_CREATION_MENU
#define DEF_USE_CHARACTER_CREATION_MENU

#include "character_menu.h"
#include "font.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Character.h"
#include "loadBaseStats.h"
#include "loadCharacterSprite.h"

#include "endSDL.h"

#include "putCCMBoxes.h"
#include "hightlightInfo.h"
#include "chooseRace.h"
#include "writeName.h"
#include "confirmCharacterCreation.h"

int	useCharacterCreationMenu(SDL_Surface *screen, Character team[4], unsigned int i);

#endif
