#include "../includes/useCharacterCreationMenu.h"

int	useCharacterCreationMenu(SDL_Surface *screen, Character team[4], unsigned int i)
{
	SDL_Surface *select;
	SDL_Surface *menu;
	SDL_Rect pos;
	SDL_Event event;
	unsigned int confirm;
	unsigned int choice;

	menu = NULL;
	select = NULL;
	choice = 0;
	confirm = 0;
	pos.x = 290 + 3 * CHARACTER_MENU_DIMENSION_MARGIN - 2;
	pos.y = 2 * CHARACTER_MENU_DIMENSION_MARGIN - 2;

	menu = IMG_Load(CHARACTER_MENU_BOX_BACKGROUND);
	if (!menu)
		fputs("IMG Error : Can't load character creation menu background\n", stderr);

	select = IMG_Load(CHARACTER_MENU_BOX_SELECT);
	if (!select)
		fputs("IMG Warning : Can't load character creation menu selection box\n", stderr);

	while (!confirm) {
		choice = pos.y / (CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX);
		if (!putCCMBoxes(screen, menu, team, i, choice)) {
			SDL_FreeSurface(select);
			SDL_FreeSurface(menu);
			fputs("Can't display character creation menu\n", stderr);
			return (0);
		}
		SDL_BlitSurface(select, NULL, screen, &pos);
		SDL_Flip(screen);

		SDL_WaitEvent(&event);
		switch (event.type) {
			case (SDL_QUIT) :
				SDL_FreeSurface(menu);
				SDL_FreeSurface(select);
				endSDL();
				exit(EXIT_SUCCESS);
				break;
			case (SDL_KEYUP) :
				switch (event.key.keysym.sym) {
					case (SDLK_UP) :
					case (SDLK_w) :
						if (pos.y > 2 * CHARACTER_MENU_DIMENSION_MARGIN)
							pos.y -= CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
						break;
					case (SDLK_DOWN) :
					case (SDLK_s) :
						if (pos.y < 4 * CHARACTER_MENU_DIMENSION_MARGIN + 2 * CHARACTER_MENU_DIMENSION_HEIGHT_BOX)
							pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
						break;
					case (SDLK_LEFT) :
					case (SDLK_RIGHT) :
					case (SDLK_d) :
					case (SDLK_a) :
						if (choice == 0) {
							if (team[i].gender == 1)
								team[i].gender = 0;
							else if (team[i].gender == 0)
								team[i].gender = 1;
							else
								fputs ("Warning : Unknown gender\n", stderr);
						} else
							hightlightInfo(screen);
						break;
					case (SDLK_RETURN) :
					case (SDLK_e) :
						switch (choice) {
							case (0) :
								hightlightInfo(screen);
								break;
							case (1) :
								if (!chooseRace(screen, &team[i].race)) {
									fputs("Error : Choosing race failed\n", stderr);
									SDL_FreeSurface(menu);
									SDL_FreeSurface(select);
									return (0);
								}
								break;
							case (2) :

								if (!team[i].name) {
									team[i].name = (char *)calloc(1, (CHARACTER_NAME_LEN_MAX + 1) * sizeof(char));
									team[i].name[CHARACTER_NAME_LEN_MAX] = '\0';
								}
								if (!writeName(screen, team[i].name)) {
									fputs("Error : Can't write name\n", stderr);
									SDL_FreeSurface(menu);
									SDL_FreeSurface(select);
									return (0);
								}
								break;
							case (3) :
								if (team[i].name && MY_str_len(team[i].name)) {
									loadBaseStats(&team[i]);
									switch (confirmCharacterCreation(screen, &team[i])) {
										case (0) :
											fputs("Error : Failed to confirm character creation\n", stderr);
											SDL_FreeSurface(menu);
											SDL_FreeSurface(select);
											return (0);
											break;
										case (1) :
											SDL_FreeSurface(menu);
											SDL_FreeSurface(select);
											team[i].confirmed = 1;
											loadCharacterSprite(&(team[i]));
											return (1);
										case (2) :
											break;
										case (3) :
											SDL_FreeSurface(menu);
											SDL_FreeSurface(select);
											exit(EXIT_SUCCESS);
											break;
										default :
											fputs("Warning : Unexpected return from creation confirmation(character)\n", stderr);
											break;
									}
								} else
									pos.y -= CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
								break;
							default :
								fputs("Error : value choice went outside of range\n", stderr);
								SDL_FreeSurface(menu);
								SDL_FreeSurface(select);
								return (0);
								break;
						}
						break;
					case (SDLK_ESCAPE) :
						SDL_FreeSurface(menu);
						SDL_FreeSurface(select);
						exit(EXIT_SUCCESS);
						break;
					default :
						hightlightInfo(screen);
						break;
				}
				break;
			default :
				break;
		}
		while(SDL_PollEvent(&event));
	}

	SDL_FreeSurface(select);
	SDL_FreeSurface(menu);
	return (1);
}
