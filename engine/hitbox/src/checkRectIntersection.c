#include "../includes/checkRectIntersection.h"

int	checkRectIntersection(SDL_Rect *rect1, SDL_Rect *rect2)
{
	if (isInRect(rect1->x, rect1->y, rect2)\
			|| isInRect(rect1->x, rect1->y + rect1->h, rect2)\
			|| isInRect(rect1->x + rect1->w, rect1->y + rect1->h, rect2)
			|| isInRect(rect1->x + rect1->w, rect1->y, rect2))
		return (1);

	if (isInRect(rect2->x, rect2->y, rect1)\
			|| isInRect(rect2->x, rect2->y + rect2->h, rect1)\
			|| isInRect(rect2->x + rect2->w, rect2->y + rect2->h, rect1)
			|| isInRect(rect2->x + rect2->w, rect2->y, rect1))
		return (-1);
	if (crossY(rect1, rect2) || crossX(rect1, rect2))
		return (1);
	if (crossY(rect2, rect1) || crossX(rect2, rect1))
		return (-1);
	return (0);
}
