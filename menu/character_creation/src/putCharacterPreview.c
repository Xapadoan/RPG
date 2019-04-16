#include "../includes/putCharacterPreview.h"

int	putCharacterPreview(SDL_Surface *dest, TTF_Font *font, Character *character, SDL_Rect *pos)
{

	SDL_Color white;

	white.r = 255;
	white.g = 255;
	white.b = 255;

	SDL_BlitSurface(character->sprite, NULL, dest, pos);
	pos->x += CHARACTER_SPRITE_SIZE_WIDTH;
	pos->y += (CHARACTER_MENU_DIMENSION_HEIGHT_BOX - TTF_FontHeight(font)) / 2 + 6;

	if (character->name && MY_str_len(character->name))
		if (!putFont(font, character->name, white, dest, pos))
			fputs("Warning : Can't put character name\n", stderr);

	pos->x -= CHARACTER_SPRITE_SIZE_WIDTH;
	pos->y -= (CHARACTER_MENU_DIMENSION_HEIGHT_BOX - TTF_FontHeight(font)) / 2 + 6;
	return (1);
}
