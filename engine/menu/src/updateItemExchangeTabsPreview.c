#include "../includes/updateItemExchangeTabsPreview.h"

int	updateItemExchangeTabsPreview(TabMenu *menu)
{
	SDL_Surface *icon;
	SDL_Rect rect;
	Tab *tab;
	int tab_width;

	tab_width = 0;
	icon = NULL;
	tab = NULL;
	rect.x = MENU_BORDERS_WIDTH;
	rect.w = menu->tabs_preview_pos.w - 2 * MENU_BORDERS_WIDTH;
	rect.y = MENU_CONTAINER_SEPARATION_WIDTH / 2;
	rect.h = menu->tabs_preview_pos.h - MENU_CONTAINER_SEPARATION_WIDTH;
	if (!menu->tabs_preview) {
		menu->tabs_preview = SDL_CreateRGBSurface(MENU_FLAGS, menu->tabs_preview_pos.w, menu->tabs_preview_pos.h, MENU_COLORS_DEPTH, 0, 0, 0, 0);
		if (!menu->tabs_preview) {
			fputs("SDL Error : Failed to create tabs preview surface\n", stderr);
			return (0);
		}
	}

	SDL_BlitSurface(menu->menu_surface, &(menu->tabs_preview_pos), menu->tabs_preview, NULL);

	if (SDL_FillRect(menu->tabs_preview,\
				&rect,\
				SDL_MapRGB(menu->tabs_preview->format,\
					MENU_COLORS_BACKGROUND_R,\
					MENU_COLORS_BACKGROUND_G,\
					MENU_COLORS_BACKGROUND_B))) {
		fputs("SDL Error : Failed to fill tabs preview\n", stderr);
		return (0);
	}

	if (!putTabsPreviewSeparation(menu)) {
		fputs("Error : Failed to put tabs preview separation\n", stderr);
		return (0);
	}

	if (!menu->tabs | !menu->tabs->first) {
		fputs("Error : Provided menu has no tab\n", stderr);
		return (0);
	}

	//Put icons
	tab_width = (menu->tabs_preview_pos.w - 2 * MENU_BORDERS_WIDTH) / menu->tabs->nb_tabs;
	rect.x = MENU_BORDERS_WIDTH + (tab_width - MENU_TABS_PREVIEW_ICON_WIDTH) / 2;
	rect.y = (menu->tabs_preview_pos.h - MENU_TABS_PREVIEW_ICON_HEIGHT - MENU_TABS_PREVIEW_SELECTION_WIDTH) / 2;
	rect.w = MENU_TABS_PREVIEW_ICON_WIDTH;
	rect.h = MENU_TABS_PREVIEW_ICON_HEIGHT;

	tab = menu->tabs->first;
	while (tab != NULL) {
		switch (tab->id) {
			case (ALL_TAB_ID) :
				icon = loadTabPreviewIcon("all");
				break;
			case (ARMOR_TAB_ID) :
				icon = loadTabPreviewIcon("armors");
				break;
			case (WEAPON_TAB_ID) :
				icon = loadTabPreviewIcon("weapons");
				break;
			case (POTION_TAB_ID) :
				icon = loadTabPreviewIcon("potions");
				break;
			case (BOOK_TAB_ID) :
				icon = loadTabPreviewIcon("books");
				break;
			case (MISC_TAB_ID) :
				icon = loadTabPreviewIcon("miscs");
				break;
			default :
				fputs("Warning : Tab id is not handled here\n", stderr);
				return (0);
		}
		if (!icon) {
			fputs("Failed to load tab preview icon\n", stderr);
			return (0);
		}
		SDL_BlitSurface(icon, NULL, menu->tabs_preview, &rect);
		SDL_FreeSurface(icon);
		icon = NULL;

		rect.x += tab_width;

		tab = tab->next;
	}

	SDL_BlitSurface(menu->tabs_preview, NULL, menu->menu_surface, &(menu->tabs_preview_pos));

	return (1);
}
