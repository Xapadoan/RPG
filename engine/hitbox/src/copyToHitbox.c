#include "../includes/copyToHitbox.h"

int	copyToHitbox(ElemHitbox *to_copy, Hitbox *hitbox)
{
	SDL_Rect pos;

	pos.x = to_copy->pos.x;
	pos.y = to_copy->pos.y;
	pos.w = to_copy->pos.w;
	pos.h = to_copy->pos.h;
	if (!addToHitbox(hitbox, &pos)) {
		fputs("Error : Failed to copy element of hitbox\n", stderr);
		return (0);
	}
	return (1);
}
