#include "../includes/MY_free_2d_char.h"

void	MY_free_2d_char(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		free(str[i++]);
	}
	free(str[i]);
	free(str);
}
