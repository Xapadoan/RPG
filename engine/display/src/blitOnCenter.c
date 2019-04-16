#include "../includes/blitOnCenter.h"

void	blitOnCenter(SDL_Surface *surf, SDL_Surface *surf2)
{
	SDL_Rect pos1;
	SDL_Rect pos2;

	pos1.x = 0;
	pos1.y = 0;
	pos1.w = 0;
	pos1.h = 0;
	pos2.x = 0;
	pos2.y = 0;
	pos2.w = 0;
	pos2.h = 0;
	if (surf->w < surf2->w) {
		pos2.x = (surf2->w - surf->w) / 2;
		pos2.w = surf->w;
	} else if (surf->w > surf2->w) {
		pos1.x = (surf->w - surf2->w) / 2;
		pos1.w = surf2->w;
	} else {
		pos1.w = surf->w;
		pos2.w = surf->w;
	}

	if (surf->h < surf2->h) {
		pos2.y = (surf2->h - surf->h) / 2;
		pos2.h = surf->h;
	} else if (surf->h > surf2->h) {
		pos1.y = (surf->h - surf2->h) / 2;
		pos1.h = surf2->h;
	} else {
		pos1.h = surf->h;
		pos2.h = surf->h;
	}

	SDL_BlitSurface(surf, &pos1, surf2, &pos2);
}
