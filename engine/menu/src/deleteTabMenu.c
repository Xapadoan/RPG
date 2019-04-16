#include "../includes/deleteTabMenu.h"

void	deleteTabMenu(TabMenu *menu)
{
	if (menu->menu_surface)
		SDL_FreeSurface(menu->menu_surface);

	if (menu->header)
		SDL_FreeSurface(menu->header);

	if (menu->tabs_preview)
		SDL_FreeSurface(menu->tabs_preview);

	if (menu->tab_content)
		SDL_FreeSurface(menu->tab_content);

	if (menu->tabs)
		deleteTabList(menu->tabs);

	if (menu->event_surface)
		SDL_FreeSurface(menu->event_surface);

	free(menu);
	menu = NULL;
}
