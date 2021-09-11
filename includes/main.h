#ifndef DEF_MAIN
#define DEF_MAIN

#include "screen.h"
#include "engine.h"
#include "music.h"
#include "sound.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "initTeam.h"
#include "deleteTeam.h"
#include "createTeam.h"
#include "Team.h"

#include "initEngine.h"
#include "endSDL.h"
#include "startPlayingMusic.h"
#include "stopPlayingMusic.h"
#include "saveTeam.h"
#include "loadTeam.h"

#include "playGame.h"

#include "useMainMenu.h"

#define EXIT_INIT()	deleteTeam(&team);\
			endSDL();\
			exit(EXIT_FAILURE);\

int	main(void);
void	setIcon(void);

#endif
