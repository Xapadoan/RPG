#include "../includes/displaySpriteList.h"

void	displaySpriteList(SDL_Surface *dest, SpriteList *list, SDL_Rect *view)
{
	SDL_Rect pos;
	ElemSpriteList *current;

	current = list->first;
	while (current->next != NULL) {
		pos.x = current->x - view->x;
		pos.y = current->y - view->y;
		pos.w = current->sprite->w;
		pos.h = current->sprite->h;
		SDL_BlitSurface(current->sprite, NULL, dest, &pos);
		current = current->next;
	}
}
