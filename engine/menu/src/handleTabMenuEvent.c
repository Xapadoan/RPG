#include "handleTabMenuEvent.h"

int	handleTabMenuEvent(TabMenu *menu, SDL_KeyboardEvent *key, unsigned int *quit) {
	Tab *active_tab;

	active_tab = NULL;
	if (!menu | !key) {
		fputs("Arg Error : Missing arguments for handleTabMenuEvent\n", stderr);
		return (0);
	}

	active_tab = getActiveTab(menu);
	if (!active_tab) {
		fputs("Error : Failed to get active tab\n", stderr);
		return (0);
	}

	switch (key->keysym.sym) {
		case (CONTROLS_MOVEMENT_UP) :
			if (active_tab->current_pos > 0)
				active_tab->current_pos--;
			else
				active_tab->current_pos = active_tab->nb_entries - 1;
			break;
		case (CONTROLS_MOVEMENT_DOWN) :
			if (active_tab->current_pos < active_tab->nb_entries - 1)
				active_tab->current_pos++;
			else
				active_tab->current_pos = 0;
			break;
		case (CONTROLS_MOVEMENT_RIGHT) :
			if (active_tab->next)
				menu->active_tab = active_tab->next->id;
			else
				menu->active_tab = menu->tabs->first->id;
			active_tab = getActiveTab(menu);
			if (!active_tab) {
				fputs("Error : Failed to get active tab\n", stderr);
				return (0);
			}
			break;
		case (CONTROLS_MOVEMENT_LEFT) :
			if (active_tab->previous)
				menu->active_tab = active_tab->previous->id;
			else {
				while (active_tab->next != NULL)
					active_tab = active_tab->next;
				menu->active_tab = active_tab->id;
			}
			active_tab = getActiveTab(menu);
			if (!active_tab) {
				fputs("Error : Failed to get active tab\n", stderr);
				return (0);
			}
			break;
		case (CONTROLS_CLOSE) :
			*quit = 1;
			break;
		case (CONTROLS_ACTION) :
			if (getDisplayTabEntry(active_tab, active_tab->current_pos)->triggerAction)
			{
				fputs("Menu trigger acions are not ready yet !", stderr);
			}
			break;
		case (CONTROLS_SWITCH) :
			break;
		default :
			break;
	}
	return (1);
}
