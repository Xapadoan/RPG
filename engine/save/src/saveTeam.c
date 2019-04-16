#include "../includes/saveTeam.h"

int	saveTeam(Team *team, const char *save_path)
{
	unsigned int i;
	FILE *file;

	file = NULL;
	i = 0;

	file = fopen(save_path, "w");
	if (!file)
	{
		fputs("File Error : Can't open save\n", stderr);
		return (0);
	}

	while (i < 4)
	{
		saveCharacter(&(team->heroes[i]), file);
		i++;
	}
	fprintf(file, "%d\t%d\n", team->location.x, team->location.y);
	fprintf(file, "%s\n", team->location.map_name);
	fputs("======", file);
	fclose(file);
	return (1);
}
