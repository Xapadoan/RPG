#ifndef DEF_GO
#define DEF_GO

#include <stdio.h>
#include <SDL/SDL.h>

#include "../../character/includes/Team.h"
#include "../../character/includes/updateTeam.h"
#include "../../location/includes/Direction.h"
#include "../../map/includes/Map.h"
#include "checkAllowedMoves.h"

void	go(Map *map, struct Team *team, int dir);

#endif
