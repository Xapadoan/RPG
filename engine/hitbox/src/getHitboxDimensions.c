#include "../includes/getHitboxDimensions.h"

SDL_Rect	getHitboxDimensions(Hitbox *hitbox)
{
	SDL_Rect dim;
	ElemHitbox *current;

	dim.x = 0;
	dim.y = 0;
	dim.w = 0;
	dim.h = 0;
	current = NULL;

	if (!hitbox || !hitbox->first) {
		fputs("Warning : Trying to get dimensions of empty hitbox\n", stderr);
		return (dim);
	}

	current = hitbox->first;
	dim.x = current->pos.x;
	dim.y = current->pos.y;
	while (current->next != NULL) {
		if (current->pos.x < dim.x)
			dim.x = current->pos.x;
		if (current->pos.y < dim.y)
			dim.y = current->pos.y;
		if (current->pos.x + current->pos.w > dim.w)
			dim.w = current->pos.x + current->pos.w;
		if (current->pos.y + current->pos.h > dim.h)
			dim.h = current->pos.y + current->pos.h;
		current = current->next;
	}

	dim.w -= dim.x;
	dim.h -= dim.y;

	return (dim);
}
