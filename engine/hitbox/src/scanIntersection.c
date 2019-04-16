#include "../includes/scanIntersection.h"

Hitbox	*scanIntersection(SDL_Rect *area, Hitbox *hitbox)
{
	unsigned int i;
	ElemHitbox *current;
	Hitbox *results;

	i = 0;
	results = initHitbox();
	current = hitbox->first;
	while (i < hitbox->len && current != NULL) {
		if (checkRectIntersection(area, &(current->pos)) != 0) {
			copyToHitbox(current, results);
		}
		current = current->next;
	}

	return (results);
}
