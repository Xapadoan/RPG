#include "../includes/updateTabContent.h"

int	updateTabContent(TabMenu *menu) {
	Tab *active_tab;
	TabEntry *current_entry;
	SDL_Rect pos;
	unsigned int nb_display;
	unsigned int i;
	SDL_Color color;

	current_entry = NULL;
	active_tab = NULL;
	i = 0;
	nb_display = 0;
	pos.x = MENU_BORDERS_WIDTH + MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
	pos.y = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
	pos.w = menu->tab_content_pos.w - MENU_SCROLLBAR_ITEM_EXCHANGE_WIDTH;
	pos.h = MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;
	color.r = MENU_COLORS_BORDERS_R;
	color.g = MENU_COLORS_BORDERS_G;
	color.b = MENU_COLORS_BORDERS_B;
	if (!menu) {
		fputs("Arg Error : Missing arguments for updateTabContent\n", stderr);
		return (0);
	}

	if (!putTabContentBackground(menu)) {
		fputs("Error : Failed to put tab content background\n", stderr);
		return (0);
	}

	if (!menu->tabs | !menu->tabs->first)
		return (1);

	active_tab = getActiveTab(menu);
	if (!active_tab) {
		fputs("Error : Failed to getActiveTab\n", stderr);
		return (0);
	} else if (active_tab->nb_entries == 0 && menu->event_surface) {
		SDL_FreeSurface(menu->event_surface);
		menu->event_surface = NULL;
	}

	nb_display = (menu->tab_content_pos.h - (MENU_CONTAINER_SEPARATION_WIDTH / 2 + MENU_BORDERS_RADIUS))\
				 / MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;

	if (active_tab->current_pos < nb_display / 2) {
		do {
			current_entry = getDisplayTabEntry(active_tab, i);
			if (!current_entry) {
				if (!putNoEntryMessage(menu, NULL)) {
					fputs("Error : Failed to put no entry message\n", stderr);
					return (0);
				}
				SDL_BlitSurface(menu->tab_content, NULL, menu->menu_surface, &(menu->tab_content_pos));
				return (1);
			}
			SDL_BlitSurface(current_entry->surface, NULL, menu->tab_content, &pos);
			if (i == active_tab->current_pos) {
				pos.y += MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT / 2;
				pos.x -= MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
				if (!drawThickCircle(menu->tab_content,\
							&pos,\
							MENU_BORDERS_WIDTH / 2 - 1,\
							MENU_BORDERS_WIDTH / 2 - 1,\
							&color,\
							CIRCLE_FULL)) {
					fputs("Error : Failed to draw selection circle\n", stderr);
					return (0);
				}
				pos.y -= MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT / 2;
				pos.x += MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_PADDING;
				if (current_entry->hoverAction != NULL)
				{
					if (!((int (*)(TabEntry *, TabMenu *))current_entry->hoverAction)(current_entry, menu)) {
						fputs("Error : Failed to perform hover action\n", stderr);
						return (0);
					}
				} else if (menu->event_surface) {
					SDL_FreeSurface(menu->event_surface);
					menu->event_surface = NULL;
				}
			}
			pos.y += MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;
			current_entry = current_entry->next;
			i++;
		} while (i < nb_display && current_entry != NULL);
	} else {
		i = active_tab->current_pos - nb_display / 2;
		do {
			current_entry = getDisplayTabEntry(active_tab, i);
			SDL_BlitSurface(current_entry->surface, NULL, menu->tab_content, &pos);
			if (i == active_tab->current_pos) {
				pos.x -= MENU_TAB_CONTENT_SELECTION_WIDTH;
				pos.y += MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT / 2;
				if (!drawThickCircle(menu->tab_content,\
							&pos,\
							MENU_TAB_CONTENT_SELECTION_WIDTH / 2 - 1,\
							MENU_TAB_CONTENT_SELECTION_WIDTH / 2 - 1,\
							&color,\
							CIRCLE_FULL)) {
					fputs("Error : Failed to draw selection circle\n", stderr);
					return (0);
				}
				pos.x += MENU_TAB_CONTENT_SELECTION_WIDTH;
				pos.y -= MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT / 2;
				if (current_entry->hoverAction != NULL)
				{
					if (!((int (*)(TabEntry *, TabMenu *))current_entry->hoverAction)(current_entry, menu)) {
						fputs("Error : Failed to perform hover action\n", stderr);
						return (0);
					}
				} else if (menu->event_surface) {
					SDL_FreeSurface(menu->event_surface);
					menu->event_surface = NULL;
				}
			}
			pos.y += MENU_TAB_CONTENT_ITEM_EXCHANGE_ENTRY_HEIGHT;
			current_entry = current_entry->next;
			i++;
		} while (i - active_tab->current_pos / 2 < nb_display\
				&& current_entry != NULL);
	}

	SDL_BlitSurface(menu->tab_content, NULL, menu->menu_surface, &(menu->tab_content_pos));

	return (1);
}
