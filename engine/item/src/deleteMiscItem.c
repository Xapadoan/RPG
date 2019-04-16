#include "../includes/deleteMiscItem.h"

void	deleteMiscItem(MiscItem *item)
{
	if (item->name)
		free(item->name);

	if (item->preview)
		SDL_FreeSurface(item->preview);

	item->next = NULL;
	free(item);
}
