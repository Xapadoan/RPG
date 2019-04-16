#include "../includes/deleteFromSpriteList.h"

int	deleteFromSpriteList(SpriteList *list, int pos)
{
	int i;
	ElemSpriteList *to_delete;
	ElemSpriteList *to_delete_prev;

	i = 0;
	to_delete = NULL;
	to_delete_prev = NULL;

	if (!list || !list->first) {
		fputs("Warning : Cannot delete from empty list\n", stderr);
		return (0);
	}

	if (pos <= 0) {
		to_delete = list->first;
		list->first = list->first->next;
	} else {
		to_delete_prev = list->first;
		while (i++ < pos && to_delete_prev->next != NULL)
			to_delete_prev = to_delete_prev->next;
		to_delete = to_delete_prev->next;
		to_delete_prev->next = to_delete_prev->next->next;
	}

	if (to_delete->sprite)
		SDL_FreeSurface(to_delete->sprite);
	free(to_delete);
	list->len--;

	return (1);
}
