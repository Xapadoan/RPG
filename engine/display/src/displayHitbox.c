#include "../includes/displayHitbox.h"

void	displayHitbox(SDL_Surface *dest, Hitbox *hitbox)
{
	SDL_Surface *surf;
	ElemHitbox *current;

	surf = NULL;
	if (!hitbox)
		fputs("Error : No hitbox to display\n", stderr);

	current = hitbox->first;
	while (current != NULL) {
		surf = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF, current->pos.w, current->pos.h, 32, 0, 0, 0, 0);
		SDL_FillRect(surf, NULL, SDL_MapRGBA(dest->format, 200, 0, 0, 100));
		SDL_BlitSurface(surf, NULL, dest, &(current->pos));
		SDL_FreeSurface(surf);
		current = current->next;
	}
}
