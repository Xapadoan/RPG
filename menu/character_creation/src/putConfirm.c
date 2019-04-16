#include "../includes/putConfirm.h"

int	putConfirm(SDL_Surface *dest, TTF_Font *font, SDL_Rect *pos_box)
{
	SDL_Rect pos;
	SDL_Color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos.x = pos_box->x + 4;
	pos.y = pos_box->y + 4;
	if (!putFont(font, "Confirm", color, dest, &pos)) {
		fputs("Error : Can't put confirm\n", stderr);
		return (0);
	}
	return (1);
}
