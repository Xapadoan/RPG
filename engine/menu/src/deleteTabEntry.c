#include "../includes/deleteTabEntry.h"

void	deleteTabEntry(TabEntry *entry)
{
	if (entry->surface)
		SDL_FreeSurface(entry->surface);

	if (entry->hoverAction)
		entry->hoverAction = NULL;

	if (entry->triggerAction)
		entry->triggerAction = NULL;

	if (entry->next)
		entry->next->previous = entry->previous;

	if (entry->previous)
		entry->previous->next = entry->next;

	if (entry->pos)
		free(entry->pos);

	if (entry->misc_content)
		free(entry->misc_content);

	entry->previous = NULL;
	entry->next = NULL;

	free(entry);
	entry = NULL;
}
