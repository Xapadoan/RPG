#include "../includes/displayMapItems.h"

void	displayMapItems(SDL_Surface *dest, MapBag *bag, SDL_Rect *view)
{
	SDL_Rect marged;
	SDL_Rect relative;
	MapItem *current;

	current = bag->first;
	while (current->next != NULL) {
		marged.x = view->x - current->pos.w;
		marged.y = view->y - current->pos.h;
		marged.w = view->w + 2 * current->pos.w;
		marged.h = view->h + 2 * current->pos.h;
		if (isInRect(current->pos.x, current->pos.y, &marged)) {
			relative.x = current->pos.x - view->x;
			relative.y = current->pos.y - view->y;
			relative.w = current->pos.w;
			relative.h = current->pos.h;
			SDL_BlitSurface(current->sprite, NULL, dest, &relative);
		}
		current = current->next;
	}
}
