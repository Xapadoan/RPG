#include "../includes/initSpriteList.h"

SpriteList	*initSpriteList(void)
{
	SpriteList *list;
	ElemSpriteList *elem;

	elem = NULL;
	list = NULL;

	list = malloc(sizeof(*list));
	elem = malloc(sizeof(*elem));

	if (!list || !elem) {
		fputs("Memory Error : Failed to allocate memory for new sprite list\n", stderr);
		return (NULL);
	}

	elem->x = 0;
	elem->y = 0;
	elem->sprite = NULL;
	elem->next = NULL;

	list->first = elem;
	list->len = 1;

	return (list);
}
