#include "../includes/saveCharacter.h"

void	saveCharacter(Character *to_save, FILE *save_file)
{
	fprintf(save_file, "%s\t%d\t%d\t%d\n", to_save->name, to_save->gender, to_save->race, to_save->level);
	fprintf(save_file, "%d\t%d\t%d\t%d\n", to_save->health, to_save->max_health, to_save->stamina, to_save->max_stamina);
	fprintf(save_file, "%d\t%d\t%d\t%d\t%d\n", to_save->strn, to_save->intel, to_save->agi, to_save->luck, to_save->acc);
	//Puts a separatinf line
	fputs("------\n", save_file);
}
