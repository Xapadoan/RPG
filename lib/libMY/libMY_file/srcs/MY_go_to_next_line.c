#include "../includes/MY_go_to_next_line.h"

int	MY_go_to_next_line(FILE *file)
{
	char a;

	a = 0;
	while (a != '\n' && a != EOF)
		a = fgetc(file);

	if (a == EOF)
		return (0);

	return (1);
}
