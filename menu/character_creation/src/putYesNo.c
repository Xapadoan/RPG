#include "../includes/putYesNo.h"

int	putYesNo(SDL_Surface *dest, TTF_Font *font, SDL_Color color)
{
	SDL_Rect pos;

	pos.x = 64;
	pos.y = 148;
	if (!putFont(font, "Yes", color, dest, &pos))
	{
		fputs("Error : Can't put yes\n", stderr);
		return (0);
	}

	pos.x += 270;
	if (!putFont(font, "No", color, dest, &pos))
	{
		fputs("Error : Can't put no\n", stderr);
		return (0);
	}

	return (1);
}
