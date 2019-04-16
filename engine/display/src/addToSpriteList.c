#include "../includes/addToSpriteList.h"

int	addToSpriteList(SpriteList *list, SDL_Surface *sprite, int x, int y)
{
	ElemSpriteList *elem;

	elem = NULL;

	elem = (ElemSpriteList *)malloc(sizeof(*elem));
	if (!elem) {
		fputs("Memory Error : Failed to allocate memory for new element of sprite list\n", stderr);
		return (0);
	}

	elem->sprite = NULL;
	elem->sprite = SDL_ConvertSurface(sprite, sprite->format, SCREEN_FLAGS);
	if (!elem->sprite) {
		fputs("SDL Error : Failed to copy sprite\n", stderr);
		return (0);
	}

	elem->x = x;
	elem->y = y;

	elem->next = list->first;
	list->first = elem;
	list->len++;

	return (1);
}
