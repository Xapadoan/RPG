#include "../includes/loadItemDescription.h"

static int	putItemName(SDL_Surface *dest, char *item_misc);

int	loadItemDescription(TabEntry *self, TabMenu *menu) {
	if (!menu | !self) {
		fputs("Arg Error : Missing arguments for loadItemDescription\n", stderr);
		return (0);
	}

	if (!menu->event_surface) {
		menu->event_surface = SDL_CreateRGBSurface(MENU_FLAGS,\
				MENU_ITEM_PREVIEW_WIDTH + 2 * MENU_ITEM_PREVIEW_BORDERS_WIDTH,\
				MENU_ITEM_PREVIEW_HEIGHT + FONT_ITEM_PREVIEW_NAME_SIZE + MENU_ITEM_PREVIEW_MARGIN + 2 * MENU_ITEM_PREVIEW_BORDERS_WIDTH,\
				MENU_COLORS_DEPTH,\
				0, 0, 0, 0);
		if (!menu->event_surface) {
			fputs("SDL Error : Failed to create RGB surface\n", stderr);
			return (0);
		}
	}

	if (!putItemName(menu->event_surface, self->misc_content)) {
		fputs("Error : Failed to write potion name\n", stderr);
		return (0);
	}

	if (!putItemPreview(menu->event_surface, self->misc_content)) {
		fputs("Error : Failed to put item preview\n", stderr);
		return (0);
	}

	if (SDL_SetColorKey(menu->event_surface, SDL_SRCCOLORKEY, SDL_MapRGB(menu->event_surface->format, 0, 0, 0)) == -1)
		fputs("Warning : Failed to set transparency for item preview\n", stderr);

	menu->event_pos.w = menu->event_surface->w;
	menu->event_pos.h = menu->event_surface->h;
	menu->event_pos.x = menu->menu_pos.x + menu->menu_pos.w + MENU_ITEM_PREVIEW_MARGIN;
	menu->event_pos.y = menu->menu_pos.y + (menu->menu_pos.h - menu->event_surface->h) / 2;

	return (1);
}

int	putItemName(SDL_Surface *dest, char *item_misc)
{
	char **item_info;
	char *name;
	SDL_Color font_color;
	SDL_Rect font_pos;
	TTF_Font *font;

	item_info = MY_str_split(item_misc, ";");
	font_color.r = MENU_COLORS_FONT_R;
	font_color.g = MENU_COLORS_FONT_G;
	font_color.b = MENU_COLORS_FONT_B;
	font = TTF_OpenFont(FONT_ITEM_PREVIEW_NAME_TYPE, FONT_ITEM_PREVIEW_NAME_SIZE);
	font_pos.y = MENU_ITEM_PREVIEW_BORDERS_RADIUS;
	font_pos.x = MENU_ITEM_PREVIEW_BORDERS_RADIUS;
	name = NULL;
	if (!item_info[0]) {
		fputs("Error : Failed to split item info\n", stderr);
		return (0);
	}
	name = MY_str_ncopy(item_info[0], 0, MY_str_len(item_info[0]));
	name = MY_replace_char(name, '_', ' ');
	MY_free_2d_char(item_info);
	if (!MY_str_capitalize(name, ' ')) {
		fputs("Error : Failed to capitalize item name\n", stderr);
		return (0);
	}
	if (!font) {
		fprintf(stderr, "TTF Error : Failed to open font for item preview name\n\t%s\n",\
				FONT_ITEM_PREVIEW_NAME_TYPE);
		return (0);
	}

	if (!putFontCenter(font, name, font_color, dest, &font_pos)) {
		fputs("Error : Failed to put item name\n", stderr);
		return (0);
	}
	free(name);
	TTF_CloseFont(font);
	return (1);
}
