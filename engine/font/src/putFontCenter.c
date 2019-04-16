#include "../includes/putFontCenter.h"

int	putFontCenter(TTF_Font *font, const char *text, const SDL_Color color, SDL_Surface *dest, SDL_Rect *pos)
{
	SDL_Surface *font_surf;
	int x;

	font_surf = NULL;
	x = pos->x;
	//Create font surface
	font_surf = TTF_RenderText_Solid(font, text, color);
	if (!font_surf) {
		//Ends if creation failed
		fputs("TTF Error : Can't render font", stderr);
		return (0);
	} else {
		//Blits font surface in the middle of dest surface
		pos->x = (dest->w - font_surf->w) / 2;
		SDL_BlitSurface(font_surf, NULL, dest, pos);
	}
	pos->x = x;
	SDL_FreeSurface(font_surf);
	return (1);
}
