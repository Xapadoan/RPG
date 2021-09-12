#include "../includes/addPotionDataToTab.h"

int	addPotionDataToTab(TabMenu *menu, Potion *potion, unsigned int tab_id)
{
	TabEntry *entry;
	Tab *tab;
	char *potion_category;
	char *potion_id;

	tab = NULL;
	entry = NULL;
	potion_category = NULL;
	if (!menu | !potion) {
		fputs("Arg Error : Missing arguments for addPotionDataToTab\n", stderr);
		return (0);
	}

	entry = initTabEntry();
	if (!entry) {
		fputs("Error : Failed to initialize tab entry\n", stderr);
		return (0);
	}

	//Go to potion tab
	if (!menu->tabs) {
		fputs("Error : Provided menu has no tab\n", stderr);
		return (0);
	}
	tab = menu->tabs->first;
	while (tab && tab->id != tab_id)
		tab = tab->next;
	if (tab->id != tab_id) {
		fprintf(stderr, "Error : Could not find potion tab (%d)\n", tab_id);
		return (0);
	}

	entry->pos->h = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;
	entry->pos->w = menu->tab_content_pos.w - MENU_SCROLLBAR_ITEM_EXCHANGE_WIDTH;

	//Set Surface
	if (!setPotionEntrySurface(entry, potion)) {
		fputs("Error : Failed to set potion entry surface\n", stderr);
		return (0);
	}

	//Set misc content
	potion_id = MY_hex2str(potion->id, 0);
	if (!potion_id) {
		fputs("MY Error : Failed to convert potion id to string\n", stderr);
		return (0);
	}
	entry->misc_content = (char *)calloc(1, (MY_str_len(potion->name) + MY_str_len(potion_id) + 4) * sizeof(char));
	if (!entry->misc_content) {
		fputs("Memory Error : Failed to allocate memory for misc content\n", stderr);
		return (0);
	}
	MY_str_append(entry->misc_content, potion->name);
	potion_category = MY_hex2str(ITEM_CATEGORY_POTION, 0);
	if (!potion_category) {
		fputs("MY Error : Failed to convert potion category to string\n", stderr);
		return (0);
	}
	MY_str_append(entry->misc_content, ";");
	MY_str_append(entry->misc_content, potion_category);
	MY_str_append(entry->misc_content, ";");
	MY_str_append(entry->misc_content, potion_id);
	free(potion_category);
	free(potion_id);

	//Set hoverAction
	entry->hoverAction = (FnctPtr)loadItemDescription;

	//Set triggerAction
	entry->triggerAction = (FnctPtr)exchangePotion;
	
	//Put at the end of tab
	if (!addEntryToTab(entry, tab, tab->nb_entries)) {
		fputs("Error : Failed to add entry to tab\n", stderr);
		return (0);
	}

	return (1);
}

int	setPotionEntrySurface(TabEntry *entry, Potion *potion) {
	char *entry_content[3];
	char *nb;
	TTF_Font *font;
	SDL_Rect font_pos;
	SDL_Color font_color;

	entry_content[0] = NULL;
	entry_content[1] = NULL;
	entry_content[2] = NULL;
	nb = NULL;
	font = NULL;
	font_pos.x = 0;
	font_pos.w = 0;
	font_pos.y = 0;
	font_pos.h = 0;
	font_color.r = MENU_COLORS_FONT_R;
	font_color.g = MENU_COLORS_FONT_G;
	font_color.b = MENU_COLORS_FONT_B;
	if (!potion | !entry) {
		fputs("Arg Error : Missing arguments for setPotionEntrySurface\n", stderr);
		return (0);
	}

	entry->surface = SDL_CreateRGBSurface(MENU_FLAGS,\
			entry->pos->w,\
			entry->pos->h,\
			MENU_COLORS_DEPTH,\
			0, 0, 0, 0);
	if (!entry->surface) {
		fputs("SDL Error : Failed to create new RGB Surface\n", stderr);
		return (0);
	}

	//Fill with background color
	if (SDL_FillRect(entry->surface, NULL, SDL_MapRGB(entry->surface->format,\
					MENU_COLORS_BACKGROUND_R,\
					MENU_COLORS_BACKGROUND_G,\
					MENU_COLORS_BACKGROUND_B))) {
		fputs("SDL Error : Failed to fill entry surface with background color\n", stderr);
		return (0);
	}

	entry_content[0] = (char *)calloc(1, (MY_str_len(potion->name) + 5) * sizeof(char));
	if (!entry_content[0]) {
		fputs("Memory Error : Failed to allocate memory for first field of potion entry content\n", stderr);
		return (0);
	}
	MY_str_append(entry_content[0], potion->name);
	MY_str_append(entry_content[0], " (");
	nb = MY_dec2str(potion->nb);
	if (!nb) {
		fputs("Error : Failed to convert potion number to string\n", stderr);
		return (0);
	}
	MY_str_append(entry_content[0], nb);
	MY_str_append(entry_content[0], ")");
	free(nb);
	nb = NULL;

	entry_content[1] = MY_dec2str(potion->weight);
	if (!entry_content[1]) {
		fputs("Error : Failed to convert potion weigth to string\n", stderr);
		return (0);
	}

	entry_content[2] = MY_dec2str(potion->value);
	if (!entry_content[2]) {
		fputs("Error : Failed to convert potion value to string\n", stderr);
		return (0);
	}

	font = TTF_OpenFont(FONT_ITEM_EXCHANGE_ITEMS_TYPE, FONT_ITEM_EXCHANGE_ITEMS_SIZE);
	if (!font) {
		fputs("TTF Error : Failed to open font for items\n", stderr);
		return (0);
	}

	//Put potion name
	font_pos.x = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING + MENU_TAB_CONTENT_SELECTION_WIDTH;
	font_pos.y = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING + (entry->pos->h - FONT_ITEM_EXCHANGE_ITEMS_SIZE) / 2;
	font_pos.w = 3 * entry->pos->w / 4 - font_pos.x;
	font_pos.h = entry->pos->h - 2 * MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
	if (!putFont(font, entry_content[0], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put potion name on entry surface\n", stderr);
		return (0);
	}

	//Put potion value
	font_pos.x = 3 * entry->pos->w / 4;
	font_pos.w = entry->pos->w / 8;
	if (!putFont(font, entry_content[1], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put potion value on entry surface\n", stderr);
		return (0);
	}

	//Put potion weight
	font_pos.x = 7 * entry->pos->w / 8;
	if (!putFont(font, entry_content[2], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put potion weight on entry surface\n", stderr);
		return (0);
	}

	free(entry_content[0]);
	free(entry_content[1]);
	free(entry_content[2]);
	TTF_CloseFont(font);
	return (1);
}
