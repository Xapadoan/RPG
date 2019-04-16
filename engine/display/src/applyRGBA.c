#include "../includes/applyRGBA.h"

int applyRGBA(SDL_Surface *surf, unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	SDL_Surface *surf2;

	surf2 = NULL;
	surf2 = SDL_CreateRGBSurface(SCREEN_FLAGS, surf->w, surf->h, SCREEN_COLORS_DEPTH, 0, 0, 0, 0);
	if (!surf2) {
		fputs("Error : Failed to create RGB Surface\n", stderr);
		return (0);
	}

	if (SDL_FillRect(surf2, NULL, SDL_MapRGB(surf2->format, r, g, b)) == -1)
		fputs("Warning : Failed to color surface\n", stderr);

	if (SDL_SetAlpha(surf2, SDL_SRCALPHA, a) == -1)
		fputs("Warning : Failed to set alpha on surface\n", stderr);

	SDL_BlitSurface(surf2, NULL, surf, NULL);
	SDL_FreeSurface(surf2);
	return (1);
}
