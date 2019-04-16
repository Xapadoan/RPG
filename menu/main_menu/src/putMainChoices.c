#include "../includes/putMainChoices.h"

int	putMainChoices(SDL_Surface *menu, SDL_Surface *screen)
{
	SDL_Surface *font_surf;
	TTF_Font *font;
	SDL_Rect pos;
	SDL_Color font_color;

	pos.x = menu->w / 4;
	pos.y = menu->h / 3;
	font_color.r = 0;
	font_color.g = 0;
	font_color.b = 0;
	font_surf = NULL;
	font = NULL;

	font = TTF_OpenFont(FONT_MAIN_MENU_TYPE, FONT_MAIN_MENU_SIZE);
	if (!font) {
		fputs("TTF Error : Can't open main menu font\n", stderr);
		return (0);
	}

	if (!putFontCenter(font, "New Game", font_color, menu, &pos))
		return (0);

	pos.y += FONT_MAIN_MENU_SIZE * 2;
	if (!putFontCenter(font, "Load Game", font_color, menu, &pos))
		return (0);

	pos.y += FONT_MAIN_MENU_SIZE * 2;
	if (!putFontCenter(font, "Exit", font_color, menu, &pos))
		return (0);

	SDL_BlitSurface(menu, NULL, screen, NULL);
	SDL_FreeSurface(font_surf);
	font_surf = NULL;
	TTF_CloseFont(font);
	font = NULL;
	return (1);
}
