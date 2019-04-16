#include "../includes/fillHoles.h"

int	fillHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width)
{
	if (!dest) {
		fputs("Error : No surface provided\n", stderr);
		return (0);
	}

	if (!color) {
		fputs("Error : No color provided\n", stderr);
		return (0);
	}

	if (!area) {
		fputs("Error : No area provided\n", stderr);
		return (0);
	}

	if (SDL_MUSTLOCK(dest)) {
		if (SDL_LockSurface(dest)) {
			fputs("SDL Error : Failed to lock surface\n", stderr);
			return (0);
		}
	}

	if (!fillXHoles(dest, area, color, hole_width)) {
		fputs("Error : Failed to fill horizontal holes\n", stderr);
		return (0);
	}

	if (!fillYHoles(dest, area, color, hole_width)) {
		fputs("Error : Failed to fill vertical holes\n", stderr);
		return (0);
	}

	if (SDL_MUSTLOCK(dest))
		SDL_UnlockSurface(dest);

	return (1);
}

int	fillXHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width)
{
	Uint8 *current_pix;
	Uint8 *next_pix;
	int bpp;
	unsigned int x_offset;
	unsigned int x_offset2;
	unsigned int y_offset;
	Uint8 *r;
	Uint8 *g;
	Uint8 *b;
	SDL_Rect to_fill;

	current_pix = NULL;
	next_pix = NULL;
	bpp = 0;
	x_offset = 0;
	x_offset2 = 0;
	y_offset = 0;
	r = NULL;
	b = NULL;
	g = NULL;
	to_fill.x = 0;
	to_fill.y = 0;
	to_fill.w = 0;
	to_fill.h = 0;
	if (!dest) {
		fputs("Error : No surface provided\n", stderr);
		return (0);
	}

	if (!color) {
		fputs("Error : No color provided\n", stderr);
		return (0);
	}

	if (!area) {
		fputs("Error : No area provided\n", stderr);
		return (0);
	}

	r = malloc(sizeof(*r));
	g = malloc(sizeof(*g));
	b = malloc(sizeof(*b));
	if (!r || !g || !b) {
		fputs("Memory Error : Failed to initialize colors\n", stderr);
		return (0);
	}

	bpp = dest->format->BytesPerPixel;
	current_pix = dest->pixels + area->y * dest->pitch + area->x * bpp;

	//Vertical loop
	while (y_offset <= area->h) {
		//Horizontal loop
		while (x_offset <= area->w) {
			SDL_GetRGB(*(Uint32 *)current_pix, dest->format, r, g, b);
			if (*r == color->r && *g == color->g && *b == color->b) {
				next_pix = current_pix + bpp;
				x_offset2 = 1;
				while (x_offset2 <= hole_width + 1 && x_offset + x_offset2 < area->w) {
					SDL_GetRGB(*(Uint32 *)next_pix, dest->format, r, g, b);
					if (*r == color->r && *g == color->g && *b == color->b) {
						to_fill.x = area->x + x_offset;
						to_fill.y = area->y + y_offset;
						to_fill.w = x_offset2;
						to_fill.h = 1;
						if (SDL_FillRect(dest, &to_fill, SDL_MapRGB(dest->format, color->r, color->g, color->b))) {
							fputs("SDL Error : Failed to fill rect\n", stderr);
							free(r);
							free(g);
							free(b);
							return (0);
						}
					}
					x_offset2++;
					next_pix = dest->pixels + (area->y + y_offset) * dest->pitch + (area->x + x_offset + x_offset2) * bpp;
				}
			}
			x_offset++;
			//goes to next line
			current_pix = dest->pixels + (area->y + y_offset) * dest->pitch + (area->x + x_offset) * bpp;
		}
		x_offset = 0;
		y_offset++;
		//warp to next column, first line
		current_pix = dest->pixels + (area->y + y_offset) * dest->pitch + area->x * bpp;
	}

	free(r);
	free(g);
	free(b);
	return (1);
}

int	fillYHoles(SDL_Surface *dest, SDL_Rect *area, SDL_Color *color, unsigned int hole_width)
{
	Uint8 *current_pix;
	Uint8 *next_pix;
	int bpp;
	unsigned int x_offset;
	unsigned int y_offset2;
	unsigned int y_offset;
	Uint8 *r;
	Uint8 *g;
	Uint8 *b;
	SDL_Rect to_fill;

	current_pix = NULL;
	next_pix = NULL;
	bpp = 0;
	x_offset = 0;
	y_offset2 = 0;
	y_offset = 0;
	r = NULL;
	b = NULL;
	g = NULL;
	to_fill.x = 0;
	to_fill.y = 0;
	to_fill.w = 0;
	to_fill.h = 0;

	if (!dest) {
		fputs("Error : No surface provided\n", stderr);
		return (0);
	}

	if (!color) {
		fputs("Error : No color provided\n", stderr);
		return (0);
	}

	if (!area) {
		fputs("Error : No area provided\n", stderr);
		return (0);
	}

	r = malloc(sizeof(*r));
	g = malloc(sizeof(*g));
	b = malloc(sizeof(*b));
	if (!r || !g || !b) {
		fputs("Memory Error : Failed to initialize colors\n", stderr);
		return (0);
	}
	*r = 0;
	*g = 0;
	*b = 0;

	bpp = dest->format->BytesPerPixel;
	current_pix = dest->pixels + area->y * dest->pitch + area->x * bpp;

	//Horizontal loop
	while (x_offset <= area->w) {
		//Horizontal loop
		while (y_offset <= area->h) {
			SDL_GetRGB(*(Uint32 *)current_pix, dest->format, r, g, b);
			if (*r == color->r && *g == color->g && *b == color->b) {
				next_pix = current_pix + dest->pitch;
				y_offset2 = 1;
				while (y_offset2 <= hole_width + 1 && y_offset + y_offset2 < area->h) {
					SDL_GetRGB(*(Uint32 *)next_pix, dest->format, r, g, b);
					if (*r == color->r && *g == color->g && *b == color->b) {
						to_fill.x = area->x + x_offset;
						to_fill.y = area->y + y_offset;
						to_fill.w = 1;
						to_fill.h = y_offset2;
						if (SDL_FillRect(dest, &to_fill, SDL_MapRGB(dest->format, color->r, color->g, color->b))) {
							fputs("SDL Error : Failed to fill rect\n", stderr);
							free(r);
							free(g);
							free(b);
							return (0);
						}
					}
					y_offset2++;
					next_pix = dest->pixels + (area->y + y_offset + y_offset2) * dest->pitch + (area->x + x_offset) * bpp;
				}
			}
			y_offset++;
			//goes to next line
			current_pix = dest->pixels + (area->y + y_offset) * dest->pitch + (area->x + x_offset) * bpp;
		}
		y_offset = 0;
		x_offset++;
		//warp to next line, first column
		current_pix = dest->pixels + (area->y) * dest->pitch + (area->x + x_offset) * bpp;
	}

	free(r);
	free(g);
	free(b);
	return (1);
}
