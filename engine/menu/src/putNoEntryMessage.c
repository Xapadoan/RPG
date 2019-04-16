#include "../includes/putNoEntryMessage.h"

int	putNoEntryMessage(TabMenu *menu, char *message) {
	SDL_Color color;
	SDL_Rect pos;
	TTF_Font *font;

	font = NULL;
	color.r = MENU_COLORS_FONT_R;
	color.g = MENU_COLORS_FONT_G;
	color.b = MENU_COLORS_FONT_B;
	pos.x = MENU_BORDERS_WIDTH;
	pos.y = MENU_BORDERS_WIDTH + MENU_DEFAULT_PADDING;

	if (!message)
		message = "There is nothing here !";

	font = TTF_OpenFont(FONT_MENU_DEFAULT_ENTRY_TYPE, FONT_MENU_DEFAULT_ENTRY_SIZE);
	if (!font) {
		fputs("TTF Error : Failed to open default entry font\n", stderr);
		return (0);
	}

	if (!putFontCenter(font, message, color, menu->tab_content, &pos)) {
		fputs("Error : Failed to put font in center of tab content\n", stderr);
		return (0);
	}

	TTF_CloseFont(font);
	return (1);
}
