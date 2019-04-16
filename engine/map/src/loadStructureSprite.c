#include "../includes/loadStructureSprite.h"

SDL_Surface	*loadStructureSprite(const char *sprite_name, SDL_Rect *pos)
{
	char *path;
	SDL_Surface *sprite;
	SDL_Surface *texture;
	SDL_Rect pos_tex;

	path = NULL;
	texture = NULL;
	sprite = NULL;
	pos_tex.x = 0;
	pos_tex.y = 0;
	pos_tex.w = 0;
	pos_tex.h = 0;
	path = (char *)calloc(1, (MY_str_len(STRUCT_SPRITE_PATH) + MY_str_len(sprite_name) + 5) * sizeof(char));
	if (!path) {
		fputs("Memory Error : Can't allocate memory for structure path\n", stderr);
		return (NULL);
	}
	MY_str_append(path, STRUCT_SPRITE_PATH);
	MY_str_append(path, sprite_name);
	MY_str_append(path, ".png");
	texture = IMG_Load(path);
	if (!texture) {
		fputs("IMG Error : Can't load structure sprite\n", stderr);
		free(path);
		return (NULL);
	}

	pos_tex.w = texture->w;
	pos_tex.h = texture->h;

	sprite = SDL_CreateRGBSurface(STRUCT_SPRITE_FLAGS, texture->w + 1, pos->h, STRUCT_SPRITE_COLORS_DEPTH, 0, 0, 0, 0);
	if (!sprite) {
		fputs("SDL Error : Can't create new surface\n", stderr);
		SDL_FreeSurface(texture);
		free(path);
		return (NULL);
	}

	while (pos_tex.y + pos_tex.h < sprite->h) {
		SDL_BlitSurface(texture, NULL, sprite, &pos_tex);
		pos_tex.y += pos_tex.h;
	}
	pos_tex.h = sprite->h - pos_tex.y;
	SDL_BlitSurface(texture, NULL, sprite, &pos_tex);

	SDL_FreeSurface(texture);
	free(path);
	return (sprite);
}
