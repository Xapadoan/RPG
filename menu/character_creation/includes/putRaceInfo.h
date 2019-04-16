#ifndef DEF_PUT_RACE_INFO
#define DEF_PUT_RACE_INFO

#include "../../../includes/config/character_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "../../../engine/character/includes/Race.h"
#include "../../../engine/font/includes/putFont.h"

int putRaceInfo(TTF_Font *font, SDL_Surface *dest, SDL_Rect *pos, const unsigned int race);
int	putRaceSkillsInfo(TTF_Font *font, SDL_Surface *dest, SDL_Rect *pos, const unsigned int race);
void	cutAtNewLine(char *str);

#endif
