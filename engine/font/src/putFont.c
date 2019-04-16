#include "../includes/putFont.h"

int	putFont(TTF_Font *font, const char *text, SDL_Color color, SDL_Surface *dest, SDL_Rect *pos)
{
	SDL_Surface *font_surf;

	font_surf = NULL;
	font_surf = TTF_RenderText_Solid(font, text, color);
	if (!font_surf) {
		fputs("TTF Error : Can't render font\n", stderr);
		return (0);
	}

	SDL_BlitSurface(font_surf, NULL, dest, pos);
	SDL_FreeSurface(font_surf);
	return (1);
}
