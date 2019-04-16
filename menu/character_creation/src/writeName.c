#include "../includes/writeName.h"

int	writeName(SDL_Surface *dest, char *name)
{
	SDL_Event event;
	SDL_Surface *background;
	SDL_Color white;
	SDL_Rect pos;
	SDL_Rect posBox;
	TTF_Font *font;
	unsigned int q;
	unsigned int lengthName;

	posBox.x = 310 + (2 * CHARACTER_MENU_DIMENSION_MARGIN);
	posBox.y = 2 * CHARACTER_MENU_DIMENSION_MARGIN + 2 * (CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX);
	pos.x = 4 + posBox.x;
	pos.y = 4 + posBox.y;
	font = NULL;
	background = NULL;
	lengthName = 0;
	white.r = 255;
	white.g = 255;
	white.b = 255;
	q = 0;

	font = TTF_OpenFont(FONT_CHARACTER_CREATION_TYPE, FONT_CHARACTER_CREATION_SIZE);
	if (!font)
	{
		fputs("TTF Error : Can't load character menu font\n", stderr);
		return (0);
	}
	pos.y += (CHARACTER_MENU_DIMENSION_HEIGHT_BOX - TTF_FontHeight(font)) / 2;
	
	background = IMG_Load(CHARACTER_MENU_BOX_NAME);
	if (!background)
	{
		fputs("IMG Error : Can't load name block", stderr);
		TTF_CloseFont(font);
		return(0);
	}

	if (!SDL_EnableUNICODE(-1))
		SDL_EnableUNICODE(1);

	//Count the length of the name
	while (name[lengthName++] != '\0');
	lengthName--;

	SDL_BlitSurface(background, NULL, dest, &posBox);
	if (MY_str_len(name) > 0 && !putFont(font, name, white, dest, &pos)) {
		fputs("Error : Can't write name\n", stderr);
		SDL_FreeSurface(background);
		TTF_CloseFont(font);
		return (0);
	}
	SDL_Flip(dest);

	while (!q)
	{
		SDL_BlitSurface(background, NULL, dest, &posBox);

		SDL_WaitEvent(&event);
		switch (event.type) {
			case (SDL_QUIT) :
				SDL_FreeSurface(background);
				TTF_CloseFont(font);
				return (0);
				break;
			case (SDL_KEYDOWN) :
			case (SDL_KEYUP) :
				if ((event.key.keysym.sym == SDLK_RETURN) && event.type == SDL_KEYUP)
					q = 1;
				addLetter(name, &lengthName, &event.key);
				if (MY_str_len(name) > 0 && !putFont(font, name, white, dest, &pos)) {
					fputs("Error : Can't write name\n", stderr);
					SDL_FreeSurface(background);
					TTF_CloseFont(font);
					return (0);
				}
				SDL_Flip(dest);
				break;
			default:
				break;
		}
	}
	TTF_CloseFont(font);
	SDL_FreeSurface(background);
	return (1);
}

void	addLetter(char *name, unsigned int *lengthName, SDL_KeyboardEvent *key)
{
	if (key->type == SDL_KEYDOWN)
	{
		if (key->keysym.unicode < 0x7F && key->keysym.unicode > 0x1F && *lengthName < CHARACTER_NAME_LEN_MAX)
		{
			name[*lengthName] = (char)key->keysym.unicode;
			(*lengthName)++;
			name[*lengthName] = '\0';
		}
		else
		{
			switch(key->keysym.sym)
			{
				case (SDLK_BACKSPACE) :
					if (*lengthName)
					{
						(*lengthName)--;
						name[*lengthName] = '\0';
					}
					break;
				default :
					break;
			}
		}
	}
}
