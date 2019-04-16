#include "../includes/isInRect.h"

int	isInRect(int x, int y, SDL_Rect *rect)
{
	if ((x > rect->x)\
			&& (x < rect->x + rect->w)\
			&& (y > rect->y)\
			&& (y < rect->y + rect->h))
		return (1);
	return (0);
}

int	crossY(SDL_Rect *rect1, SDL_Rect *rect2)
{
	//If x1 < x2 < x1 + w1 || x1 < x2 + w2 < x1 + w1
	if (((rect1->x < rect2->x && rect2->x < rect1->x + rect1->w)\
			|| (rect1->x < rect2->x + rect2->w && rect2->x + rect2->w < rect1->x + rect1->w))\
		//y2 < y1 < y1 + h1 < y2 + h2 || y1 < y2 < y2 + h2 < y1 + h1
			&& ((rect2->y < rect1->y && rect1->y + rect1->h < rect2->y + rect2->h)\
			|| (rect1->y < rect2->y && rect2->y + rect2->h < rect1->y + rect1->h)))
		return (1);
	return (0);
}

int	crossX(SDL_Rect *rect1, SDL_Rect *rect2)
{
	//If x1 < x2 < x1 + w1 || x1 < x2 + w2 < x1 + w1
	if (((rect1->y < rect2->y && rect2->y < rect1->y + rect1->h)\
			|| (rect1->y < rect2->y + rect2->h && rect2->y + rect2->h < rect1->y + rect1->h))\
		//y2 < y1 < y1 + h1 < y2 + h2 || y1 < y2 < y2 + h2 < y1 + h1
			&& ((rect2->x < rect1->x && rect1->x + rect1->w < rect2->x + rect2->w)\
			|| (rect1->x < rect2->x && rect2->x + rect2->w < rect1->x + rect1->w)))
		return (1);
	return (0);
}
