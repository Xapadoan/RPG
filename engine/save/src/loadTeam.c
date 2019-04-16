#include "../includes/loadTeam.h"

int	loadTeam(Team *team, const char *save_path){
	unsigned int i;
	FILE *file;
	char *str;

	str = NULL;
	str = (char *)calloc(1, 100 * sizeof(char));
	file = NULL;
	i = 0;

	file = fopen(save_path, "r");
	if (!file){
		fputs("File Error : Can't open save\n", stderr);
		return (0);
	}

	while (i < 4){
		loadCharacter(&(team->heroes[i]), file);
		loadCharacterSprite(&(team->heroes[i]));
		i++;
	}
	i = 0;
	fscanf(file, "%x\t%x\n", &(team->location.x), &(team->location.y));
	fscanf(file, "%s\n", str);
	fclose(file);
	team->location.map_name = (char *)calloc(1, (MY_str_len(str) + 1) * sizeof(char));
	if (!team->location.map_name) {
		fputs("Memory Error : Failed to allocate memory for map name\n", stderr);
		return (0);
	}
	MY_str_append(team->location.map_name, str);
	free(str);
	return (1);
}
