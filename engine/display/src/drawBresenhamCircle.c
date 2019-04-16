#include "../includes/drawBresenhamCircle.h"

int	drawBresenhamCircle(SDL_Surface *dest, SDL_Rect *origin, unsigned int r, SDL_Color *color, unsigned int flags)
{
	int x;
	int y;

	if (!dest) {
		fputs("Error : No surface provided\n", stderr);
		return (0);
	}

	if (!origin) {
		fputs("Error : No origin provided\n", stderr);
		return (0);
	}

	x = r;
	y = 0;

	//Lock Surface
	if (SDL_MUSTLOCK(dest)) {
		if (SDL_LockSurface(dest)) {
			fputs("SDL Error : Failed to lock surface\n", stderr);
			return (0);
		}
	}

	//Draw
	while (MY_abs(x) >= MY_abs(y)) {
		//put colors on chosen portions
		if (flags & CIRCLE_PORTION_0) {
			if (!putPixel(dest, origin->x + x, origin->y + y, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_1) {
			if (!putPixel(dest, origin->x - y, origin->y - x, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_2) {
			if (!putPixel(dest, origin->x + y, origin->y - x, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_3) {
			if (!putPixel(dest, origin->x - x, origin->y + y, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_4) {
			if (!putPixel(dest, origin->x - x, origin->y - y, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_5) {
			if (!putPixel(dest, origin->x + y, origin->y + x, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_6) {
			if (!putPixel(dest, origin->x - y, origin->y + x, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		if (flags & CIRCLE_PORTION_7) {
			if (!putPixel(dest, origin->x + x, origin->y - y, color)) {
				fputs("Error : Failed to put color\n", stderr);
				return (0);
			}
		}

		//choose current_pos (x, y - 1) or (x - 1, y -1)
		if (MY_abs(x * x + (y - 1) * (y - 1) - r * r)\
				> MY_abs((x - 1) * (x - 1) + (y - 1) * (y - 1) - r * r)) {
			y--;
			x--;
		} else {
			y--;
		}

	}

	//Unlock Surface
	if (SDL_MUSTLOCK(dest))
		SDL_UnlockSurface(dest);

	return (1);
}
