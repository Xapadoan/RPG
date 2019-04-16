#include "../includes/putRace.h"

int	putRace(SDL_Surface *dest, TTF_Font *font, unsigned int race, SDL_Rect *posBloc)
{
	SDL_Color white;
	SDL_Rect pos;
	char *race_name;

	race_name = NULL;
	white.r = 255;
	white.g = 255;
	white.b = 255;
	pos.x = posBloc->x + 4;
	pos.y = posBloc->y + (CHARACTER_MENU_DIMENSION_HEIGHT_BOX - TTF_FontHeight(font)) / 2;
	switch (race) {
		case (CORAN) :
			race_name = "Coran";
			break;
		case (HUMAN) :
			race_name = "Human";
			break;
		case (SANAK) :
			race_name = "Sanak";
			break;
		case (DWARF) :
			race_name = "Dwarf";
			break;
		case (FAIRY) :
			race_name = "Fairy";
			break;
		case (ELF) :
			race_name = "Elf";
			break;
		default:
			fputs("Error : Unknown race\n", stderr);
			return (0);
			break;
	}

	if (!putFont(font, race_name, white, dest, &pos)) {
		fputs("Error : Can't put race\n", stderr);
		return (0);
	}

	return (1);
}
