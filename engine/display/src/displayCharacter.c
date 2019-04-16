#include "../includes/displayCharacter.h"

int	displayCharacter(SDL_Surface *map, Character *character, SDL_Rect *pos, int sprite_id) {
	SDL_Rect pos_surf;

	if (!character || !character->sprite) {
		fputs("Warning : Tried to display NULL character, or with no sprite\n", stderr);
		return (0);
	}
	pos_surf.x = pos->x - character->sprite->w / 2;
	pos_surf.y = pos->y - character->sprite->h / 2;
	pos_surf.w = character->sprite->w;
	pos_surf.h = character->sprite->h;

	if (!map) {
		fputs("Error : There is no map\n", stderr);
		return (0);
	}

	switch (sprite_id) {
		case (1) :
			SDL_BlitSurface(character->sprite, NULL, map, &pos_surf);
			break;
		case (2) :
			SDL_BlitSurface(character->sprite2, NULL, map, &pos_surf);
			break;
		case (3) :
			SDL_BlitSurface(character->sprite3, NULL, map, &pos_surf);
			break;
		default :
			fputs("Error : Unknown sprite id\n", stderr);
			return (0);
			break;
	}
	return (1);
}
