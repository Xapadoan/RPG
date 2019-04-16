#include "../includes/initHitbox.h"

Hitbox	*initHitbox(void)
{
	Hitbox *hitbox;
	ElemHitbox *elem;

	hitbox = NULL;
	elem = NULL;

	hitbox = malloc(sizeof(*hitbox));
	elem = malloc(sizeof(*elem));

	if (!hitbox || !elem) {
		fputs("Memory Error : Failed to allocate memory for new hitbox\n", stderr);
		return (NULL);
	}

	elem->pos.x = 0;
	elem->pos.y = 0;
	elem->pos.w = 0;
	elem->pos.h = 0;
	elem->next = NULL;
	hitbox->first = elem;
	hitbox->len = 1;
	return (hitbox);
}
