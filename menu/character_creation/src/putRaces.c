#include "../includes/putRaces.h"

int	putRaces(TTF_Font *font, SDL_Surface *dest)
{
	SDL_Rect pos;
	SDL_Color white;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	pos.x = CHARACTER_MENU_DIMENSION_MARGIN + 4;
	pos.y = (2 * CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_RACE_HEIGHT) + 6;

	if (!putFont(font, "Human", white, dest, &pos))
	{
		fputs("Warning : Can't write HUMAN\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;

	if (!putFont(font, "Sanak", white, dest, &pos))
	{
		fputs("Warning : Can't write SANAK\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;

	if (!putFont(font, "Dwarf", white, dest, &pos))
	{
		fputs("Warning : Can't write DWARF\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;

	pos.x += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_WIDTH_BOX;
	pos.y = (2 * CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_RACE_HEIGHT) + 6;
	if (!putFont(font, "Coran", white, dest, &pos))
	{
		fputs("Warning : Can't write CORAN\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;

	if (!putFont(font, "Fairy", white, dest, &pos))
	{
		fputs("Warning : Can't write FAIRY\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;

	if (!putFont(font, "Elve", white, dest, &pos))
	{
		fputs("Warning : Can't write ELVE\n", stderr);
		return (0);
	}
	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
	return (1);
}
