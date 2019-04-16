#ifndef DEF_MAIN
#define DEF_MAIN

#include "screen.h"
#include "engine.h"
#include "music.h"
#include "sound.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "../engine/character/includes/initTeam.h"
#include "../engine/character/includes/deleteTeam.h"
#include "../engine/character/includes/createTeam.h"
#include "../engine/character/includes/Team.h"

#include "../engine/includes/initEngine.h"
#include "../engine/includes/endSDL.h"
#include "../engine/music/includes/startPlayingMusic.h"
#include "../engine/music/includes/stopPlayingMusic.h"
#include "../engine/save/includes/saveTeam.h"
#include "../engine/save/includes/loadTeam.h"

#include "../engine/play/includes/playGame.h"

#include "../menu/main_menu/includes/useMainMenu.h"

#define EXIT_INIT()	deleteTeam(&team);\
			endSDL();\
			exit(EXIT_FAILURE);\

int	main(void);
void	setIcon(void);

#endif
