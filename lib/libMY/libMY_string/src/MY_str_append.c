#include "../includes/MY_str_append.h"

void	MY_str_append(char *main, const char *to_add)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = MY_str_len(main);
	while (to_add[i] != '\0')
	{
		main[j++] = to_add[i++];
	}
	main[j] = '\0';
}
