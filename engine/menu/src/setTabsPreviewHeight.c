#include "../includes/setTabsPreviewHeight.h"

int	setTabsPreviewHeight(TabMenu *menu, unsigned int height)
{
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	menu->tabs_preview_pos.h = height;

	menu->tab_content_pos.h = menu->menu_pos.h - (menu->header_pos.h + menu->tabs_preview_pos.h);
	menu->tab_content_pos.y = menu->header_pos.h + menu->tabs_preview_pos.h;

	return (1);
}
