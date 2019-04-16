#include "../includes/putCharacterInfo.h"

int	putCharacterInfo(SDL_Surface *screen, Character *to_display, TTF_Font *font, SDL_Color color, SDL_Rect *posText)
{
	SDL_Rect pos;
	char *race_id;

	pos.x = posText->x + 330;
	pos.y = posText->y;
	race_id = NULL;

	if (!putFont(font, to_display->name, color, screen, &pos))
	{
		fputs("Error : Can't put character name\n", stderr);
		return (0);
	}

	pos.y = posText->y + TTF_FontHeight(font) + 4;
	pos.x = posText->x;

	if (!putFont(font, "A", color, screen, &pos))
	{
		fputs("Error : Can't put A\n", stderr);
		return (0);
	}

	pos.x += 30;
	if (to_display->gender == 1)
	{
		if (!putFont(font, "Female", color, screen, &pos))
		{
			fputs("Error : Can't write FEMALE\n", stderr);
			return (0);
		}
		pos.x += 115;
	}
	else if (!to_display->gender)
	{
		if (!putFont(font, "Male", color, screen, &pos))
		{
			fputs("Error : Can't write MALE\n", stderr);
			return (0);
		}
		pos.x += 80;
	}
	else
	{
		fputs ("Error : Unknown gender\n", stderr);
		return (0);
	}

	switch (to_display->race)
	{
		case (HUMAN) :
			race_id = "Human";
			break;
		case (CORAN) :
			race_id = "Coran";
			break;
		case (SANAK) :
			race_id = "Sanak";
			break;
		case (FAIRY) :
			race_id = "Fairy";
			break;
		case (DWARF) :
			race_id = "Dwarf";
			break;
		case (ELF) :
			race_id = "Elf";
			break;
		default :
			fputs("Error : Unknown race\n", stderr);
			return (0);
	}

	if (!putFont(font, race_id, color, screen, &pos))
	{
		fputs("Error : Can't put race\n", stderr);
		return (0);
	}

	return (1);
}
