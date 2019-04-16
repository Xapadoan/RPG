#include "../includes/updateItemExchangeHeader.h"

int	updateItemExchangeHeader(TabMenu *menu, ItemBag *bag, const char *name)
{
	TTF_Font *font;
	SDL_Rect font_pos;
	SDL_Color font_color;
	char *copper;
	char *copper_line;
	char *cap_name;

	cap_name = NULL;
	font = NULL;
	font_pos.x = menu->header_pos.x + MENU_BORDERS_RADIUS / 2 + MENU_BORDERS_WIDTH;
	font_pos.y = menu->header_pos.y + MENU_BORDERS_RADIUS / 2 + MENU_BORDERS_WIDTH;
	font_color.r = MENU_COLORS_FONT_R;
	font_color.g = MENU_COLORS_FONT_G;
	font_color.b = MENU_COLORS_FONT_B;
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!bag) {
		fputs("Error : No item bag provided\n", stderr);
		return (0);
	}

	if (!putTabMenuHeaderBackground(menu)) {
		fputs("Error : Faield to put header background\n", stderr);
		return (0);
	}

	cap_name = (char *)calloc(1, (MY_str_len(name) + 1) * sizeof(char));
	if (!cap_name) {
		fputs("Memory Error : Failed to allocate memory for capitalized name\n", stderr);
		return (0);
	}

	MY_str_append(cap_name, name);

	if (!MY_str_capitalize(cap_name, '_')) {
		fputs("Error : Failed to capitalize name\n", stderr);
		return (0);
	}

	font = TTF_OpenFont(FONT_ITEM_EXCHANGE_CONTAINER_NAME_TYPE,\
			2 * (menu->header_pos.h - MENU_BORDERS_WIDTH - MENU_CONTAINER_SEPARATION_WIDTH/ 2) / 3 - MENU_HEADER_MARGIN);
	if (!font) {
		fputs("TTF Error : Failed to open font for name\n", stderr);
		fprintf(stderr, "%s\n", FONT_ITEM_EXCHANGE_CONTAINER_NAME_TYPE);
		return (0);
	}

	if (!putFont(font, cap_name, font_color, menu->header, &font_pos)) {
		fputs("Error : Failed to put font\n", stderr);
		return (0);
	}
	TTF_CloseFont(font);

	font = TTF_OpenFont(FONT_ITEM_EXCHANGE_COPPER_TYPE,\
			(menu->header_pos.h - MENU_BORDERS_WIDTH - MENU_CONTAINER_SEPARATION_WIDTH) / 3 - MENU_HEADER_MARGIN);
	if (!font) {
		fputs("TTF Error : Failed to open font for copper\n", stderr);
		return (0);
	}

	font_pos.x = menu->header_pos.w / 2;
	font_pos.y = menu->header_pos.h - TTF_FontHeight(font) - MENU_HEADER_MARGIN - MENU_CONTAINER_SEPARATION_WIDTH / 2;

	copper = MY_dec2str(bag->copper);
	if (!copper) {
		fputs("Error : Failed to convert copper to string\n", stderr);
		return (0);
	}

	copper_line = (char *)calloc(1, (MY_str_len(copper) + 10) * sizeof(char));
	if (!copper_line) {
		fputs("Memory Error : Failed to allocate memory for copper line\n", stderr);
		return (0);
	}

	MY_str_append(copper_line, "copper : ");
	MY_str_append(copper_line, copper);

	if (!putFont(font, copper_line, font_color, menu->header, &font_pos)) {
		fputs("Error : Failed to put font\n", stderr);
		return (0);
	}
	TTF_CloseFont(font);

	SDL_BlitSurface(menu->header, NULL, menu->menu_surface, &(menu->header_pos));

	free(cap_name);
	free(copper);
	free(copper_line);
	return (1);
}
