#include "../includes/confirmCharacterCreation.h"

int	confirmCharacterCreation(SDL_Surface *screen, Character *to_confirm)
{
	SDL_Surface *confirm;
	SDL_Surface *select;
	SDL_Rect pos;
	SDL_Rect posSelect;
	SDL_Event event;
	unsigned int q;
	unsigned int choice;

	q = 0;
	choice = 0;
	pos.x = 50;
	pos.y = CHARACTER_MENU_DIMENSION_MARGIN + screen->h / 3;
	posSelect.x = 58 + pos.x;
	posSelect.y = 138 + pos.y;
	confirm = NULL;
	select = NULL;

	confirm = prepareConfirmScreen(to_confirm);
	if (!confirm)
	{
		fputs("Error : Can't prepare confirmation screen\n", stderr);
		SDL_FreeSurface(confirm);
		SDL_FreeSurface(select);
		return (0);
	}

	select = IMG_Load(CHARACTER_MENU_BOX_CONFIRM_SELECT);
	if (!select)
	{
		fputs("IMG Error : Can't load confirm_selected.png", stderr);
		SDL_FreeSurface(confirm);
		SDL_FreeSurface(select);
		return (0);
	}

	while (!q)
	{
		SDL_BlitSurface(confirm, NULL, screen, &pos);
		SDL_BlitSurface(select, NULL, screen, &posSelect);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case (SDL_QUIT) :
				SDL_FreeSurface(confirm);
				SDL_FreeSurface(select);
				return (3);
				break;
			case (SDL_KEYUP) :
				q = chooseConfirm(&posSelect, &event.key, &choice);
				break;
			default :
				break;
		}
	}

	SDL_FreeSurface(select);
	SDL_FreeSurface(confirm);
	return (choice);
}
