#include "../includes/setTabMenuHeight.h"

int	setTabMenuHeight(TabMenu *menu, unsigned int height)
{
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	menu->menu_pos.h = height;

	menu->tab_content_pos.h = height - (menu->header_pos.h + menu->tabs_preview_pos.h);

	return (1);
}
