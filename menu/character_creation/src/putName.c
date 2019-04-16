#include "../includes/putName.h"

int	putName(SDL_Surface *dest, TTF_Font *font, const char *name, SDL_Rect *pos_box)
{
	SDL_Rect pos;
	SDL_Color white;

	pos.x = pos_box->x + 4;
	pos.y = pos_box->y + (CHARACTER_MENU_DIMENSION_HEIGHT_BOX - TTF_FontHeight(font)) / 2;
	white.r = 255;
	white.g = 255;
	white.b = 255;

	if (!putFont(font, name, white, dest, &pos)) {
		fputs("Error : Can't put name\n", stderr);
		return (0);
	}
	return (1);
}
