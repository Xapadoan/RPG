#include "../includes/initTabEntry.h"

TabEntry *initTabEntry(void)
{
	TabEntry *entry;

	entry = (TabEntry *)malloc(sizeof(*entry));
	if (!entry) {
		fputs("Memory Error : Failed to allocate memory for tab entry\n", stderr);
		return (NULL);
	}

	entry->pos = (SDL_Rect *)malloc(sizeof(*(entry->pos)));
	if (!entry->pos) {
		fputs("Memory Error : Failed to allocate memory for entry position\n", stderr);
		return (NULL);
	}

	entry->pos->x = 0;
	entry->pos->w = 0;
	entry->pos->y = 0;
	entry->pos->h = 0;

	entry->display_pos = 0;

	entry->surface = NULL;
	entry->misc_content = NULL;
	entry->hoverAction = NULL;
	entry->triggerAction = NULL;
	entry->next = NULL;
	entry->previous = NULL;

	return (entry);
}
