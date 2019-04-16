#include "../includes/loadBaseStats.h"

int	loadBaseStats(Character *character)
{
	switch(character->race)
	{
		case (HUMAN) :
			character->intel += 10;
			break;
		case (CORAN) :
			character->agi += 10;
			character->acc += 10;
			character->max_health -= 10;
			break;
		case (SANAK) :
			character->strn += 10;
			character->agi -= 10;
			character->max_health += 10;
			break;
		case (FAIRY) :
			character->luck += 10;
			character->agi += 10;
			character->max_health -= 20;
			break;
		case (DWARF) :
			character->strn += 10;
			character->max_health += 20;
			character->agi -= 10;
			character->acc -= 10;
			break;
		case (ELF) :
			character->agi += 10;
			character->acc += 10;
			character->strn -= 10;
			break;
		default :
			fputs("Error : Unknown race\n", stderr);
			return (0);
			break;
	}
	return (1);
}
