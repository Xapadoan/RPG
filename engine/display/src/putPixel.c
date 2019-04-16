#include "../includes/putPixel.h"

int	putPixel(SDL_Surface *dest, int x, int y, SDL_Color *color)
{
	int bpp;
	Uint32 pixel;
	Uint8 *pix;
	
	pixel = SDL_MapRGB(dest->format, color->r, color->g, color->b);
	bpp = dest->format->BytesPerPixel;
	pix = (Uint8 *)dest->pixels + y * dest->pitch + x * bpp;

	switch (bpp) {
		case (1) :
			*pix = pixel;
			break;
		case (2) :
			*(Uint16 *)pix = pixel;
			break;
		case (4) :
			*(Uint32 *)pix = pixel;
			break;
		default :
			fputs("Error : No support for surface's format\n", stderr);
			return (0);
			break;
	}

	return (1);
}
