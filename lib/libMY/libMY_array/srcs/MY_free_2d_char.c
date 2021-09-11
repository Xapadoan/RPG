#include "../includes/MY_free_2d_char.h"

void	MY_free_2d_char(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++]);
	}
	free(str[i]);
	free(str);
}
