#include "../includes/putTitleScreen.h"

int	putTitleScreen(SDL_Surface *screen)
{
	SDL_Rect pos;
	TTF_Font *font;
	SDL_Color font_color;
	SDL_Surface *menu;

	font = NULL;
	menu = NULL;
	font_color.r = 0;
	font_color.g = 0;
	font_color.b = 0;
	pos.x = 0;
	pos.y = 0;

	menu = IMG_Load(ART_MAIN_MENU_BACKGROUND);
	if (!menu) {
		fputs("IMG Error : Can't load title screen background.png\n", stderr);
		return (0);
	}

	font = TTF_OpenFont(FONT_TITLE_SCREEN_TYPE, FONT_TITLE_SCREEN_SIZE);
	if (!font) {
		fputs("TTF Error : Can't load title screen font\n", stderr);
		SDL_FreeSurface(menu);
		return (0);
	} else {
		pos.x = menu->w / 2;
		pos.y = menu->h / 2 - 20;
		if (!putFontCenter(font, "Press any key !", font_color, menu, &pos)) {
			fputs("Title screen Error : Can't put font\n", stderr);
			SDL_FreeSurface(menu);
			return (0);
		}
	}

	SDL_BlitSurface(menu, NULL, screen, NULL);
	SDL_Flip(screen);

	TTF_CloseFont(font);
	font = NULL;

	SDL_FreeSurface(menu);
	menu = NULL;

	return (1);
}
