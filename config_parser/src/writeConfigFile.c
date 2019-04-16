#include "../includes/writeConfigFile.h"

void	writeConfigFile(FILE *file, char *str)
{
	char *to_write;

	to_write = NULL;
	to_write = (char *)calloc(1, (MY_str_len(str) + 9) * sizeof(char));
	MY_str_append(to_write, "#define ");
	MY_str_append(to_write, str);

	fputs(to_write, file);
	free(to_write);
}
