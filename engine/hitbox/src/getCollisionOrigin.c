#include "../includes/getCollisionOrigin.h"

int	getCollisionOrigin(SDL_Rect *origin, SDL_Rect *other, int margin)
{
	int dir;

	dir = 0;

	//We check if the next position of the point in the middle of each side of the rect
	//won't be in the 'other' rect, if so, that direction causes the collision
	if (isInRect(origin->x + origin->w / 2, origin->y - margin, other)\
			|| isInRect(other->x + other->w / 2, other->y + other->h + margin, origin))
		dir |= UP;
	if (isInRect(origin->x + origin->w / 2, origin->y + origin->h + margin, other)\
			|| isInRect(other->x + other->w / 2, other->y - margin, origin))
		dir |= DOWN;
	if (isInRect(origin->x + origin->w + margin, origin->y + origin->h / 2, other)\
			|| isInRect(other->x - margin, other->y + other->y / 2, origin))
		dir |= RIGHT;
	if (isInRect(origin->x - margin, origin->y + origin->h / 2, other)\
			|| isInRect(other->x + other->w + margin, other->y + other->h / 2, origin))
		dir |= LEFT;

	if (dir)
		return (dir);

	//We check if point close to each corner are in the 'other' rect, we can deduce the
	//direction of the collision when we know witch point is in the 'other' rect
	if (isInRect(origin->x, origin->y, other)) {
		if (isInRect(origin->x + margin, origin->y - margin, other))
			dir |= UP;
		if (isInRect(origin->x - margin, origin->y + margin, other))
			dir |= LEFT;
	}
	if (isInRect(origin->x, origin->y + origin->h, other)) {
		if (isInRect(origin->x + margin, origin->y + origin->h + margin, other))
			dir |= DOWN;
		if (isInRect(origin->x - margin, origin->y + origin->h - margin, other))
			dir |= LEFT;
	}
	if (isInRect(origin->x + origin->w, origin->y + origin->h, other)) {
		if (isInRect(origin->x + origin->w - margin, origin->y + origin->h + margin, other))
			dir |= DOWN;
		if (isInRect(origin->x + origin->w + margin, origin->y + origin->h - margin, other))
			dir |= RIGHT;
	}
	if (isInRect(origin->x + origin->w, origin->y, other)) {
		if (isInRect(origin->x + origin->w - margin, origin->y - margin, other))
			dir |= UP;
		if (isInRect(origin->x + origin->w + margin, origin->y + margin, other))
			dir |= RIGHT;
	}

	return (dir);
}
