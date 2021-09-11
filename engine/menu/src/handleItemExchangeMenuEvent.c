#include <unistd.h>
#include "handleItemExchangeMenuEvent.h"

int processItemAction(Tab *active_tab, TabMenu *menu) {
	TabEntry	*entry;
	char			**splitted_misc;
	int				item_category;

	if (!active_tab) {
		fputs("Arg Error : Missing argument for processItemAction\n", stderr);
		return (0);
	}
	entry = getDisplayTabEntry(active_tab, active_tab->current_pos);
	if (!entry) {
		fputs("Error : Failed to get selected entry\n", stderr);
		return (0);
	}
	if (!entry->triggerAction)
		return (1);
	splitted_misc = MY_str_split(entry->misc_content, ";");
	if (!splitted_misc) {
		fputs("Error : Failed to split misc content\n", stderr);
		return (0);
	}
	item_category = MY_hex2dec(splitted_misc[1]);
	switch(item_category) {
		case (ITEM_CATEGORY_POTION):
			if (!((int (*)(int, PotionBag *, PotionBag *))entry->triggerAction)(MY_hex2dec(splitted_misc[2]), ((Team *)menu->refs[0])->bag->potions, ((MapItem *)menu->refs[1])->items->potions)) {
				fputs("Error : Failed to trigger potion action\n", stderr);
				return (0);
			}
			break;
		default:
			fputs("Warning : Unknow item category\n", stderr);
			break;
	}
	return (1);
}

int	handleItemExchangeMenuEvent(TabMenu *menu, SDL_KeyboardEvent *key, unsigned int *quit) {
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
				write(1, "Menu trigger acions are not ready yet !\n", 40);
			}
			break;
		case (CONTROLS_SWITCH) :
			break;
		default :
			break;
	}
	return (1);
}
