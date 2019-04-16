#include "../includes/chooseRace.h"

int	chooseRace(SDL_Surface *screen, unsigned int *race)
{
	SDL_Surface *background;
	SDL_Surface *select;
	TTF_Font *fontRace;
	TTF_Font *fontDescribe;
	SDL_Rect posRace;
	SDL_Event event;
	unsigned int q;

	q = 0;
	fontRace = NULL;
	fontDescribe = NULL;
	background = NULL;
	select = NULL;
	posRace.x = CHARACTER_MENU_DIMENSION_MARGIN - 2;
	posRace.y = (2 * CHARACTER_MENU_DIMENSION_MARGIN) + CHARACTER_MENU_DIMENSION_RACE_HEIGHT - 2;

	background = IMG_Load(CHARACTER_MENU_BOX_RM_BACKGROUND);
	if (!background) {
		fputs("IMG Error : Can't load race_menu_background.png\n", stderr);
		FREE_RACE();
		return (0);
	}

	select = IMG_Load(CHARACTER_MENU_BOX_RM_SELECT);
	if (!select)
	{
		fputs("IMG Error : Can't load race_selected_bloc.png\n", stderr);
		FREE_RACE();
		return (0);
	}

	fontDescribe = TTF_OpenFont(FONT_RACE_MENU_DESCRIPTION_TYPE, FONT_RACE_MENU_DESCRIPTION_SIZE);
	if (!fontDescribe)
	{
		fputs("TTF Error : Can't load font alagard.ttf\n", stderr);
		FREE_RACE();
		return (0);
	}

	fontRace = TTF_OpenFont(FONT_CHARACTER_CREATION_TYPE, FONT_CHARACTER_CREATION_SIZE);
	if (!fontRace)
	{
		fputs("TTF Error : Can't load font alagard\n", stderr);
		FREE_RACE();
		return (0);
	}

	while (!q)
	{
		SDL_BlitSurface(background, NULL, screen, NULL);
		showRaceDescription(fontDescribe, screen, *race);
		if (!putRaces(fontRace, screen))
			fputs("Warning : Can't put Races\n", stderr);
		SDL_BlitSurface(select, NULL, screen, &posRace);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case (SDL_QUIT) :
				FREE_RACE();
				endSDL();
				exit(EXIT_SUCCESS);
				break;
			case (SDL_KEYUP) :
				q = useRaceMenu(&posRace, race, &event.key);
				break;
			default :
				break;
		}
	}

	FREE_RACE();
	return (1);
}
