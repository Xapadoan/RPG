#include "../includes/putTabsPreviewSeparation.h"

int	putTabsPreviewSeparation(TabMenu *menu)
{
	Tab *tab;
	SDL_Color color;
	unsigned int i;
	SDL_Rect sep_pos;
	int tab_width;

	i = 0;
	tab_width = 0;
	sep_pos.w = MENU_TABS_PREVIEW_SEPARATION_WIDTH;
	sep_pos.h = 2 * menu->tabs_preview_pos.h / 3;
	sep_pos.x = MENU_BORDERS_WIDTH;
	sep_pos.y = menu->tabs_preview_pos.h / 3;
	color.r = MENU_COLORS_BORDERS_R;
	color.g = MENU_COLORS_BORDERS_G;
	color.b = MENU_COLORS_BORDERS_B;
	tab = NULL;
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	if (!menu->tabs | !menu->tabs->first) {
		fputs("Error : Menu has no tabs\n", stderr);
		return (0);
	}

	tab = menu->tabs->first;
	tab_width = (menu->tabs_preview_pos.w - 2 * MENU_BORDERS_WIDTH) / menu->tabs->nb_tabs;
	while (tab) {
		sep_pos.x += tab_width;
		if (SDL_FillRect(menu->tabs_preview, &sep_pos, SDL_MapRGB(menu->tabs_preview->format,\
						color.r, color.g, color.b))) {
			fputs("SDL_Error : Failed to fill rect\n", stderr);
			return (0);
		}

		if (tab->id == menu->active_tab) {
			sep_pos.w = MENU_TABS_PREVIEW_SELECTION_WIDTH;
			sep_pos.x -= MENU_TABS_PREVIEW_SELECTION_WIDTH + 1;
			sep_pos.h -= 1;
			if (SDL_FillRect(menu->tabs_preview, &sep_pos, SDL_MapRGB(menu->tabs_preview->format,\
							MENU_COLORS_SELECTION_R,\
							MENU_COLORS_SELECTION_G,\
							MENU_COLORS_SELECTION_B))) {
				fputs("SDL Error : Failed to fill selection vertical rect\n", stderr);
				return (0);
			}

			sep_pos.w = tab_width - 2 * (MENU_TABS_PREVIEW_SELECTION_WIDTH + 1);
			sep_pos.x -= sep_pos.w;
			sep_pos.y = menu->tabs_preview_pos.h - (MENU_CONTAINER_SEPARATION_WIDTH / 2 + MENU_TABS_PREVIEW_SELECTION_WIDTH + 2);
			sep_pos.h = MENU_TABS_PREVIEW_SELECTION_WIDTH;
			if (SDL_FillRect(menu->tabs_preview, &sep_pos, SDL_MapRGB(menu->tabs_preview->format,\
							MENU_COLORS_SELECTION_R,\
							MENU_COLORS_SELECTION_G,\
							MENU_COLORS_SELECTION_B))) {
				fputs("SDL Error : Failed to fill selection vertical rect\n", stderr);
				return (0);
			}

			sep_pos.x = MENU_BORDERS_WIDTH + (1 + i) * tab_width;
			sep_pos.w = MENU_TABS_PREVIEW_SEPARATION_WIDTH;
			sep_pos.y = menu->tabs_preview_pos.h / 3;
			sep_pos.h = 2 * menu->tabs_preview_pos.h / 3;
		}

		i++;
		tab = tab->next;
	}

	i = 0;
	sep_pos.x = MENU_BORDERS_WIDTH - (menu->tabs_preview_pos.h / 3);
	while (i++ < menu->tabs->nb_tabs - 1) {
		sep_pos.x += tab_width;
		if (!drawBresenhamCircle(menu->tabs_preview, &sep_pos, menu->tabs_preview_pos.h / 3, &color, CIRCLE_TOP_RIGHT_CORNER)) {
			fputs("Error : Failed to put tab separation corner\n", stderr);
			return (0);
		}
	}

	return (1);
}
