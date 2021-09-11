#ifndef DEF_PLAY_GAME
#define DEF_PLAY_GAME

#include <stdio.h>
#include <SDL/SDL.h>

#include "Team.h"
#include "deleteTeam.h"
#include "handleStateChange.h"
#include "initMap.h"
#include "loadMap.h"
#include "Map.h"
#include "deleteMap.h"
#include "displayMap.h"
#include "handlePressedKeys.h"
#include "triggerKeyUp.h"

int	playGame(SDL_Surface *screen, Team *team);

#endif
