#ifndef DEF_CREATE_TEAM
#define DEF_CREATE_TEAM

#include <stdio.h>
#include <SDL/SDL.h>

#include "Team.h"
#include "enterMap.h"
#include "initTeam.h"

#include "../../../menu/character_creation/includes/useCharacterCreationMenu.h"

int	createTeam(SDL_Surface *screen, struct Team *team);

#endif
