#include "deleteMiscBag.h"

void	deleteMiscBag(MiscBag *items)
{
	MiscItem *item;

	item = items->first;
	while (item) {
		items->first = item->next;
		deleteMiscItem(item);
		item = items->first;
	}

	free(items);
}
