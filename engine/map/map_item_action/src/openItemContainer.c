#include "../includes/openItemContainer.h"

int	openItemContainer(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv)
{
	TabMenu *menu;
	SDL_Surface *background;
	unsigned int quit;
	SDL_Event event;

	background = NULL;
	quit = 0;
	if (!map || !team || !argv)
	//Prepare background screen
	background = prepareExchangeScreen(self->name, screen);
	if (!background) {
		fputs("Error : Faield to prepare exchange screen\n", stderr);
		return (0);
	}

	//Initialize TabMenu
	menu = initTabMenu();
	if (!menu) {
		fputs("Error : Failed to initialize menu\n", stderr);
		return (0);
	}

	if (!createItemExchangeTabs(menu)) {
		fputs("Error : Failed to create item exchange tabs\n", stderr);
		return (0);
	}

	//Set TabMenu dimensions
	if (!setTabMenuWidth(menu, background->w / 2)) {
		fputs("Error : Failed to set menu width\n", stderr);
		return (0);
	}

	if (!setTabMenuHeight(menu, 3 * background->h / 4)) {
		fputs("Error : Failed to set menu height\n", stderr);
		return (0);
	}

	if (!setTabMenuHeaderHeight(menu, MENU_HEADER_ITEM_EXCHANGE_HEIGHT)) {
		fputs("Error : Failed to set menu header height\n", stderr);
		return (0);
	}

	if (!setTabsPreviewHeight(menu, MENU_TABS_PREVIEW_ITEM_EXCHANGE_HEIGHT)) {
		fputs("Error : Faield to set tabs preview height\n", stderr);
		return (0);
	}

	menu->menu_pos.x = (background->w - menu->menu_pos.w) / 4;
	menu->menu_pos.y = (background->h - menu->menu_pos.h) / 2;

	//Load Items
	if (!loadItemExchangeMenuContent(menu, self->items)) {
		fputs("Error : Failed to load items on menu\n", stderr);
		return (0);
	}
	menu->active_tab = menu->tabs->first->id;
	
	//Begin loop
	while (!quit) {
		//Update menu
		if (!updateItemExchangeMenu(menu, self)) {
			fputs("Error : Failed to update item exchange menu\n", stderr);
			return (0);
		}

		SDL_BlitSurface(background, NULL, screen, NULL);
		if (menu->event_surface)
			SDL_BlitSurface(menu->event_surface, NULL, screen, &(menu->event_pos));
		SDL_BlitSurface(menu->menu_surface, NULL, screen, &(menu->menu_pos));
		SDL_Flip(screen);

		SDL_WaitEvent(&event);
		switch (event.type) {
			case (SDL_QUIT) :
				exit(EXIT_SUCCESS);
				break;
			case (SDL_KEYUP) :
				if (!handleTabMenuEvent(menu, &(event.key), &quit)) {
					fputs("Error : Failed to handle tab menu event\n", stderr);
					return (0);
				}
				break;
			default :
				break;
		}
	}
	deleteTabMenu(menu);
	SDL_FreeSurface(background);
	return (1);
}
