#include "../includes/useMainMenu.h"

int useMainMenu(SDL_Surface *screen)
{
	SDL_Event event;
	SDL_Surface *menu;
	int qTitle;
	int choice;

	qTitle = 0;
	choice = 0;
	menu = NULL;

	if (!putTitleScreen(screen)) {
		fputs("Main menu Error : Can't put title screen\n", stderr);
		return (0);
	}

	menu = IMG_Load(ART_MAIN_MENU_BACKGROUND);
	if (!menu) {
		fputs("Main menu Error : Can't load background\n", stderr);
		return (0);
	}

	while (!qTitle) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case (SDL_QUIT) :
				EXIT_MENU();
				break;
			case (SDL_KEYUP) :
				if (!putMainChoices(menu, screen)) {
					SDL_FreeSurface(menu);
					return (0);
				}
				if (moveMainCursor(menu, screen, &choice))
					qTitle = 1;
				break;
			default :
				break;
		}
	}
	SDL_FreeSurface(menu);
	menu = NULL;
	return (choice);
}
