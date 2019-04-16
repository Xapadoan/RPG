#include "../includes/setTabMenuWidth.h"

int	setTabMenuWidth(TabMenu *menu, unsigned int width)
{
	if (!menu) {
		fputs("Error : No menu provided\n", stderr);
		return (0);
	}

	menu->menu_pos.w = width;

	menu->header_pos.w = width;

	menu->tabs_preview_pos.w = width;

	menu->tab_content_pos.w = width;

	return (1);
}
