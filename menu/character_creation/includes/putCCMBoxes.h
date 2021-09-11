#ifndef DEF_PUT_CCM_BOXES
#define DEF_PUT_CCM_BOXES

#include "character_menu.h"
#include "font.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "putTeamInfo.h"
#include "putGender.h"
#include "putRace.h"
#include "putName.h"
#include "putConfirm.h"
#include "putUserInfo.h"

#include "MY_string.h"

int	putCCMBoxes(SDL_Surface *screen, SDL_Surface *menu, Character team[4], const unsigned int i, const unsigned int choice);

#endif
