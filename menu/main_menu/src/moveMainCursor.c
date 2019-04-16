#include "../includes/moveMainCursor.h"

int	moveMainCursor(SDL_Surface *menu, SDL_Surface *screen, int *choice)
{
	SDL_Surface *cursor;
	SDL_Rect pos;
	SDL_Event event;

	cursor = NULL;
	pos.x = 0;
	pos.y = 0;

	cursor = IMG_Load(INTERFACE_SPRITE_MAIN_MENU_CURSOR);
	if (!cursor) {
		fputs("IMG Error : Can't load main menu cursor\n", stderr);
		return (0);
	}

	pos.x = menu->w / 2 - (5 * cursor->w);
	pos.y = menu->h / 3 + (FONT_MAIN_MENU_SIZE - cursor->h) / 2;

	while (!(*choice)) {
		if (!putMainChoices(menu, screen)) {
			SDL_FreeSurface(cursor);
			return (0);
		}

		SDL_BlitSurface(cursor, NULL, screen, &pos);
		SDL_Flip(screen);

		SDL_WaitEvent(&event);
		switch(event.type) {
			case (SDL_KEYUP) :
				switch(event.key.keysym.sym) {
					case (SDLK_w) :
					case (SDLK_UP) :
						pos.y -= FONT_MAIN_MENU_SIZE * 2;
						if (!testPosMainCursor(menu, &pos))
							pos.y += FONT_MAIN_MENU_SIZE * 2;
						break;
					case (SDLK_s) :
					case (SDLK_DOWN) :
						pos.y += FONT_MAIN_MENU_SIZE * 2;
						if (!testPosMainCursor(menu, &pos))
							pos.y -= FONT_MAIN_MENU_SIZE * 2;
						break;
					case (SDLK_e) :
					case (SDLK_RETURN) :
						*choice = 1 + ((pos.y - menu->w / 4) / (FONT_MAIN_MENU_SIZE * 2));
						break;
					case (SDLK_ESCAPE) :
						SDL_FreeSurface(cursor);
						SDL_FreeSurface(menu);
						SDL_FreeSurface(screen);
						endSDL();
						exit(EXIT_SUCCESS);
						break;
					default :
						break;
				}
				break;
			case (SDL_QUIT) :
				SDL_FreeSurface(cursor);
				SDL_FreeSurface(menu);
				SDL_FreeSurface(screen);
				endSDL();
				exit(EXIT_SUCCESS);
				break;
			default :
				break;
			}
		}
	SDL_FreeSurface(cursor);
	return (1);
}

int	testPosMainCursor(SDL_Surface *menu, SDL_Rect *pos)
{
	if (pos->y < menu->h / 3)
		return (0);
	if (pos->y > (menu->h / 3 + 6 * FONT_MAIN_MENU_SIZE))
		return (0);
	return (1);
}
