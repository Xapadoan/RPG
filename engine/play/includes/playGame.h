#ifndef DEF_PLAY_GAME
#define DEF_PLAY_GAME

#include <stdio.h>
#include <SDL/SDL.h>

#include "../../character/includes/Team.h"
#include "../../character/includes/deleteTeam.h"
#include "../../character/includes/handleStateChange.h"
#include "../../map/includes/initMap.h"
#include "../../map/includes/loadMap.h"
#include "../../map/includes/Map.h"
#include "../../map/includes/deleteMap.h"
#include "../../display/includes/displayMap.h"
#include "../../move/includes/handlePressedKeys.h"
#include "triggerKeyUp.h"

int	playGame(SDL_Surface *screen, Team *team);

#endif
