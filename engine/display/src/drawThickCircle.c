#include "../includes/drawThickCircle.h"

int	drawThickCircle(SDL_Surface *dest, SDL_Rect *origin, unsigned int r, unsigned int thickness, SDL_Color *color, unsigned int flags)
{
	unsigned int i;
	SDL_Rect draw_area;

	i = r;

	//choose area.x
	if (flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4))
		draw_area.x = origin->x - r;
	else if (flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_5))
		draw_area.x = origin->x - r / 2;
	else if (flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_6 | CIRCLE_PORTION_0 | CIRCLE_PORTION_7))
		draw_area.x = origin->x;
	else
		return (1);

	//choose area.w
	if ((flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4))\
			&& (flags & (CIRCLE_PORTION_0 | CIRCLE_PORTION_7)))
		draw_area.w = 2 * r;
	else if (((flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4))\
				&& (flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_6))\
				&& !(flags & (CIRCLE_PORTION_0 | CIRCLE_PORTION_7)))\
			|| ((flags & (CIRCLE_PORTION_0 | CIRCLE_PORTION_7))\
				&& (flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_5))\
				&& !(flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4))))
		draw_area.w = 3 * r / 2;
	else if (((flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4))\
				&& !(flags & (CIRCLE_RIGHT_HALF)))\
			|| ((flags & (CIRCLE_PORTION_0 | CIRCLE_PORTION_7))\
				&& !(flags & (CIRCLE_LEFT_HALF)))\
			|| ((flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_5))\
				&& (flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_6))\
				&& !(flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4 | CIRCLE_PORTION_0 | CIRCLE_PORTION_7))))
		draw_area.w = r;
	else if (((flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_5))\
				&& !(flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_4 | CIRCLE_RIGHT_HALF)))\
			|| ((flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_6))\
				&& !(flags & (CIRCLE_PORTION_7 | CIRCLE_PORTION_0 | CIRCLE_LEFT_HALF))))
		draw_area.w = r / 2;
	else {
		fputs("Notice : Circle has null width\n", stderr);
		return (1);
	}

	//choose area.y
	if (flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_2))
		draw_area.y = origin->y - r;
	else if (flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_0))
		draw_area.y = origin->y - r / 2;
	else if (flags & (CIRCLE_PORTION_4 | CIRCLE_PORTION_7 | CIRCLE_PORTION_5 | CIRCLE_PORTION_6))
		draw_area.y = origin->y;
	else
		return (1);

	//choose area.h
	if ((flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_1))\
			&& (flags & (CIRCLE_PORTION_5 | CIRCLE_PORTION_6)))
		draw_area.h = 2 * r;
	else if (((flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_2))\
				&& (flags & (CIRCLE_PORTION_4 | CIRCLE_PORTION_7))\
				&& !(flags & (CIRCLE_PORTION_5 | CIRCLE_PORTION_6)))\
			|| ((flags & (CIRCLE_PORTION_5 | CIRCLE_PORTION_6))\
				&& (flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_0))\
				&& !(flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_2))))
		draw_area.h = 3 * r / 2;
	else if (((flags & (CIRCLE_PORTION_2 | CIRCLE_PORTION_1))\
				&& !(flags & (CIRCLE_BOTTOM_HALF)))\
			|| ((flags & (CIRCLE_PORTION_5 | CIRCLE_PORTION_6))\
				&& !(flags & (CIRCLE_TOP_HALF)))\
			|| ((flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_0))\
				&& (flags & (CIRCLE_PORTION_4 | CIRCLE_PORTION_7))\
				&& !(flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_2 | CIRCLE_PORTION_5 | CIRCLE_PORTION_6))))
		draw_area.h = r;
	else if (((flags & (CIRCLE_PORTION_3 | CIRCLE_PORTION_0))\
				&& !(flags & (CIRCLE_PORTION_1 | CIRCLE_PORTION_2 | CIRCLE_BOTTOM_HALF)))\
			|| ((flags & (CIRCLE_PORTION_4 | CIRCLE_PORTION_7))\
				&& !(flags & (CIRCLE_PORTION_5 | CIRCLE_PORTION_6 | CIRCLE_TOP_HALF))))
		draw_area.h = r / 2;
	else {
		fputs("Notice : Circle has null height\n", stderr);
		return (1);
	}

	if (!dest) {
		fputs("Error : No surface provided\n", stderr);
		return (0);
	}

	if (!origin) {
		fputs("Error : No origin provided\n", stderr);
		return (0);
	}

	while (i > r - thickness) {
		if (!drawBresenhamCircle(dest, origin, i, color, flags)) {
			fputs("Error : Failed to draw bresenham circle\n", stderr);
			return (0);
		}
		i--;
	}

	if (!fillHoles(dest, &draw_area, color, 1))
		fputs("Warning : Failed to fill holes\n", stderr);

	return (1);
}
