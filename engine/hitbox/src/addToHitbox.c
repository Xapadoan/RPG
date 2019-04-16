#include "../includes/addToHitbox.h"

int	addToHitbox(Hitbox *hitbox, SDL_Rect *value)
{
	ElemHitbox	*new;

	new = NULL;

	if (!hitbox) {
		fputs("Warning : hitbox was not initialized\n", stderr);
		return (0);
	}

	new = (ElemHitbox *)malloc(sizeof(*new));
	if (!new) {
		fputs("Memory Error : Failed to allocate memory for adding to hitbox\n", stderr);
		return (0);
	}

	new->pos.x = value->x;
	new->pos.y = value->y;
	new->pos.w = value->w;
	new->pos.h = value->h;
	new->next = hitbox->first;
	hitbox->first = new;
	hitbox->len++;
	return (1);
}
