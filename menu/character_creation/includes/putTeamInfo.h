#ifndef DEF_PUT_TEAM_INFO
#define DEF_PUT_TEAM_INFO

#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/character/includes/Character.h"
#include "putTeamInfo.h"
#include "putCharacterPreview.h"

int	putTeamInfo(SDL_Surface *menu, TTF_Font *font, Character team[4]);

#endif
