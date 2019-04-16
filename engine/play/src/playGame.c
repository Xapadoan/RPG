#include "../includes/playGame.h"

int	playGame(SDL_Surface *screen, Team *team)
{
	int quit;
	int t0;
	int t1;
	SDL_Event event;
	Map map;

	quit = 0;
	t0 = SDL_GetTicks();
	t1 = 0;
	event.type = 0;
	initMap(&map);

	if (!loadMap(&map, team->location.map_name)) {
		fputs("Error : Failed to load map\n", stderr);
		return (0);
	}

	while (!quit) {
		t1 = SDL_GetTicks();
		if (t1 - t0 < 100) {
			SDL_Delay(100 - (t1 - t0));
		} else {
			t0 = t1;
		}

		if (!handleStateChange(team)) {
			fputs("Error : Failed to handle state change\n", stderr);
			deleteMap(&map);
			return (0);
		}
		if (!displayMap(screen, &map, team)) {
			fputs("Error : Failed to display map\n", stderr);
			deleteMap(&map);
			return (0);
		}
		SDL_Flip(screen);

		SDL_PollEvent(&event);
		switch (event.type) {
			case (SDL_QUIT) :
				deleteMap(&map);
				return (1);
				break;
			case (SDL_KEYUP) :
				if (!triggerKeyUp(screen, &map, team, &(event.key))) {
					quit = 1;
				}
				break;
			default :
				break;
		}
		event.type = 0;
		if (!handlePressedKeys(&map, team)) {
			fputs("Error : Failed to handle pressed keys\n", stderr);
			return (0);
		}
	}
	deleteMap(&map);
	return (1);
}
