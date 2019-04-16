#include "../includes/loadCharacter.h"

void	loadCharacter(Character *to_load, FILE *save_file){
	char line[20];
	
	fscanf(save_file, "%s\t%u\t%u\t%u\n", line, &to_load->gender, &to_load->race, &to_load->level);
	fscanf(save_file, "%d\t%d\t%d\t%d\n", &to_load->health, &to_load->max_health, &to_load->stamina, &to_load->max_stamina);
	fscanf(save_file, "%u\t%u\t%u\t%u\t%u\n", &to_load->strn, &to_load->intel, &to_load->agi, &to_load->luck, &to_load->acc);
	to_load->name = (char *)calloc(1, (MY_str_len(line) + 1) * sizeof(char));
	MY_str_append(to_load->name, line);
	//Jumps the separating lines
	fgets(line, 20, save_file);
}
