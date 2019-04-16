#include "../includes/loadMapStructures.h"

void	loadMapStructures(SDL_Surface *map, const char *path)
{
	FILE *file;
	int rad;
	SDL_Surface *sprite;
	SDL_Surface *rot;
	char sprite_name[50];
	SDL_Rect pos;

	file = NULL;
	rot = NULL;
	sprite = NULL;
	pos.x = 0;
	pos.y = 0;
	pos.h = 0;
	rad = 0;

	file = fopen(path, "r");
	while (fscanf(file, "%s\t%d\t%hx\t%hx\t%hx\n", sprite_name, &rad, &(pos.x), &(pos.y), &(pos.h)) != EOF) {
		sprite = loadStructureSprite(sprite_name, &pos);
		if (!sprite)
			fputs("Warning : Failed to load structure sprite\n", stderr);
		rot = rotozoomSurface(sprite, (double)rad, 1.0, 0);
		if (!rot)
			fputs("Warning : Failed to rotate structure sprite\n", stderr);
		SDL_FreeSurface(sprite);
		pos.w = rot->w;
		pos.h = rot->h;
		SDL_BlitSurface(rot, NULL, map, &pos);
		SDL_FreeSurface(rot);
	}

	fclose(file);
}
