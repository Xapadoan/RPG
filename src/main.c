#include "../includes/main.h"

int	main(void)
{
	Team team;
	SDL_Surface *screen;
	Mix_Music *music;

	screen = NULL;
	music = NULL;
	initTeam(&team);

	if (!initEngine(ENGINE_INIT_SDL_FLAGS, ENGINE_INIT_IMG_FLAGS, MIX_INIT_MOD)) {
		fputs("Engine Error : Can't init engine\n", stderr);
		EXIT_INIT();
	}

	setIcon();
	SDL_WM_SetCaption("Stay Alert !", NULL);
	SDL_ShowCursor(0);

	screen = SDL_SetVideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT,\
			SCREEN_COLORS_DEPTH, SCREEN_FLAGS);
	if (!screen) {
		fputs("SDL Error : Can't create screen\n", stderr);
		EXIT_INIT();
	}

	//Pre game actions : loading or creating game
	music = startPlayingMusic(MUSIC_TITLE_SCREEN, SOUND_VOLUME_MUSIC);
	switch(useMainMenu(screen))
	{
		case (0) :
			fputs("\nMain Menu Error\n------\n", stderr);
			Mix_FreeMusic(music);
			EXIT_INIT();
			break;
		case (1) :
			if (!createTeam(screen, &team)) {
				fputs("\nGame Creation Error\n------\n", stderr);
				Mix_FreeMusic(music);
				EXIT_INIT();
			}
			if (!saveTeam(&team, "save/save_01.save"))
				fputs ("Warning : Saving game failed\n", stderr);
			break;
		case (2) :
			if (!loadTeam(&team, "save/save_01.save")) {
				fputs("\nGame Loading Error\n------\n", stderr);
				Mix_FreeMusic(music);
				EXIT_INIT();
			}
			break;
		case (3) :
			Mix_FreeMusic(music);
			deleteTeam(&team);
			endSDL();
			exit(EXIT_SUCCESS);
			break;
		default :
			break;
	}
	stopPlayingMusic(music, 1000);

	//Playing game
	if (!playGame(screen, &team)) {
		fputs("\nGame Execution Error\n------\n", stderr);
		EXIT_INIT();
	}

	deleteTeam(&team);
	endSDL();
	return (EXIT_SUCCESS);
}

void	setIcon(void)
{
	SDL_Surface *icon;

	icon = NULL;
	icon = SDL_LoadBMP("resource/images/icon.bmp");
	if (!icon)
		fputs("Warning : Failed to load icon\n", stderr);
	SDL_WM_SetIcon(icon, NULL);
	SDL_FreeSurface(icon);
}
