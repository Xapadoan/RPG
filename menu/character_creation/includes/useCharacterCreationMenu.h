#ifndef DEF_USE_CHARACTER_CREATION_MENU
#define DEF_USE_CHARACTER_CREATION_MENU

#include "../../../includes/config/character_menu.h"
#include "../../../includes/config/font.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../../../engine/character/includes/Character.h"
#include "../../../engine/character/includes/loadBaseStats.h"
#include "../../../engine/character/includes/loadCharacterSprite.h"

#include "../../../engine/includes/endSDL.h"

#include "putCCMBoxes.h"
#include "hightlightInfo.h"
#include "chooseRace.h"
#include "writeName.h"
#include "confirmCharacterCreation.h"

int	useCharacterCreationMenu(SDL_Surface *screen, Character team[4], unsigned int i);

#endif
