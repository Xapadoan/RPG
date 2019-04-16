#include "addBookDataToTab.h"

static int	setBookEntrySurface(TabEntry *entry, Book *book) {
	char *entry_content[3];
	TTF_Font *font;
	SDL_Rect font_pos;
	SDL_Color font_color;

	entry_content[0] = NULL;
	entry_content[1] = NULL;
	entry_content[2] = NULL;
	font = NULL;
	font_pos.x = 0;
	font_pos.w = 0;
	font_pos.y = 0;
	font_pos.h = 0;
	font_color.r = MENU_COLORS_FONT_R;
	font_color.g = MENU_COLORS_FONT_G;
	font_color.b = MENU_COLORS_FONT_B;
	if (!book | !entry) {
		fputs("Arg Error : Missing arguments for setBookEntrySurface\n", stderr);
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

	entry_content[0] = (char *)calloc(1, (MY_str_len(book->name) + 5) * sizeof(char));
	if (!entry_content[0]) {
		fputs("Memory Error : Failed to allocate memory for first field of book entry content\n", stderr);
		return (0);
	}
	MY_str_append(entry_content[0], book->name);

	entry_content[1] = MY_dec2str(book->weight);
	if (!entry_content[1]) {
		fputs("Error : Failed to convert book weigth to string\n", stderr);
		return (0);
	}

	entry_content[2] = MY_dec2str(book->value);
	if (!entry_content[2]) {
		fputs("Error : Failed to convert book value to string\n", stderr);
		return (0);
	}

	font = TTF_OpenFont(FONT_ITEM_EXCHANGE_ITEMS_TYPE, FONT_ITEM_EXCHANGE_ITEMS_SIZE);
	if (!font) {
		fputs("TTF Error : Failed to open font for items\n", stderr);
		return (0);
	}

	//Put book name
	font_pos.x = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING + MENU_TAB_CONTENT_SELECTION_WIDTH;
	font_pos.y = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING + (entry->pos->h - FONT_ITEM_EXCHANGE_ITEMS_SIZE) / 2;
	font_pos.w = 3 * entry->pos->w / 4 - font_pos.x;
	font_pos.h = entry->pos->h - 2 * MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
	if (!putFont(font, entry_content[0], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put book name on entry surface\n", stderr);
		return (0);
	}

	//Put book value
	font_pos.x = 3 * entry->pos->w / 4;
	font_pos.w = entry->pos->w / 8;
	if (!putFont(font, entry_content[1], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put book value on entry surface\n", stderr);
		return (0);
	}

	//Put book weight
	font_pos.x = 7 * entry->pos->w / 8;
	if (!putFont(font, entry_content[2], font_color, entry->surface, &font_pos)) {
		fputs("Error : Failed to put book weight on entry surface\n", stderr);
		return (0);
	}

	free(entry_content[0]);
	free(entry_content[1]);
	free(entry_content[2]);
	TTF_CloseFont(font);
	return (1);
}

int	addBookDataToTab(TabMenu *menu, Book *book)
{
	TabEntry *entry;
	Tab *tab;
	char *book_category;

	book_category = NULL;
	if (!menu | !book) {
		fputs("Arg Error : Missing arguments for addBookDataToTab\n", stderr);
		return (0);
	}

	//Create new entry
	entry = initTabEntry();
	if (!entry) {
		fputs("Error : Failed to initialize tab entry\n", stderr);
		return (0);
	}

	//Go to book tab
	if (!menu->tabs) {
		fputs("Error : Provided menu has no tab\n", stderr);
		return (0);
	}

	tab = menu->tabs->first;
	while (tab && tab->id != BOOK_TAB_ID)
		tab = tab->next;
	if (tab->id != BOOK_TAB_ID) {
		fputs("Error : Could not fing book tab\n", stderr);
		return (0);
	}

	entry->pos->h = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;
	entry->pos->w = menu->tab_content_pos.w - MENU_SCROLLBAR_ITEM_EXCHANGE_WIDTH;

	//Set Surface
	if (!setBookEntrySurface(entry, book)) {
		fputs("Error : Failed to set book entry surface\n", stderr);
		return (0);
	}

	//Set misc content
	entry->misc_content = (char *)calloc(1, (MY_str_len(book->name) + 3) * sizeof(char));
	if (!entry->misc_content) {
		fputs("Memory Error : Failed to allocate memory for misc content\n", stderr);
		return (0);
	}
	MY_str_append(entry->misc_content, book->name);
	book_category = MY_hex2char(ITEM_CATEGORY_BOOK);
	if (!book_category) {
		fputs("MY Error : Failed to convert book category to string\n", stderr);
		return (0);
	}
	MY_str_append(entry->misc_content, ";");
	MY_str_append(entry->misc_content, book_category);
	free(book_category);

	//Set hoverAction
	entry->hoverAction = (FnctPtr)loadItemDescription;

	//Set triggerAction
	
	//Put at the end of tab
	if (!addEntryToTab(entry, tab, tab->nb_entries)) {
		fputs("Error : Failed to add entry to tab\n", stderr);
		return (0);
	}

	//Put at end of All tab
	tab = menu->tabs->first;
	if (!addEntryToTab(entry, tab, tab->nb_entries)) {
		fputs("Error : Failed to add entry to tab\n", stderr);
		return (0);
	}

	return (1);
}
