#include "../includes/initTabMenu.h"

TabMenu	*initTabMenu(void)
{
	TabMenu *menu;

	menu = NULL;
	menu = malloc(sizeof(*menu));
	if (!menu) {
		fputs("Memory Error : Failed to allocate memory for menu\n", stderr);
		return (NULL);
	}

	menu->menu_pos.x = 0;
	menu->menu_pos.y = 0;
	menu->menu_pos.w = 0;
	menu->menu_pos.h = 0;
	menu->menu_surface = NULL;

	menu->header_pos.x = 0;
	menu->header_pos.y = 0;
	menu->header_pos.w = 0;
	menu->header_pos.h = 0;
	menu->header = NULL;

	menu->tabs_preview_pos.x = 0;
	menu->tabs_preview_pos.y = 0;
	menu->tabs_preview_pos.w = 0;
	menu->tabs_preview_pos.h = 0;
	menu->tabs_preview = NULL;

	menu->active_tab = 0;
	menu->tab_content_pos.x = 0;
	menu->tab_content_pos.y = 0;
	menu->tab_content_pos.w = 0;
	menu->tab_content_pos.h = 0;
	menu->tab_content = NULL;

	menu->event_pos.x = 0;
	menu->event_pos.y = 0;
	menu->event_pos.w = 0;
	menu->event_pos.h = 0;
	menu->event_surface = NULL;

	menu->tabs = initTabList();
	if (!menu->tabs) {
		fputs("Error : Failed to init Tabs\n", stderr);
		return (NULL);
	}

	return (menu);
}
