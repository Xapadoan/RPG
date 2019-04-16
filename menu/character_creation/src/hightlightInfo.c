#include "../includes/hightlightInfo.h"

void	hightlightInfo(SDL_Surface *dest)
{
	SDL_Surface *light;
	SDL_Surface *unlight;
	SDL_Rect pos;

	light = NULL;
	unlight = NULL;
	pos.x = CHARACTER_MENU_DIMENSION_MARGIN - 2;
	pos.y = 5 * CHARACTER_MENU_DIMENSION_MARGIN\
			+ 4 * CHARACTER_MENU_DIMENSION_HEIGHT_BOX - 2;

	light = IMG_Load(CHARACTER_MENU_BOX_LIGHT);
	if (!light)
		fputs("Warning : Can't load user info hightlighter\n", stderr);
	unlight = IMG_Load(CHARACTER_MENU_BOX_UNLIGHT);
	if (!unlight)
		fputs("Warning : Can't load user info lowlighter\n", stderr);

	SDL_BlitSurface(light, NULL, dest, &pos);
	SDL_Flip(dest);
	SDL_Delay(50);

	SDL_BlitSurface(unlight, NULL, dest, &pos);
	SDL_Flip(dest);
}
