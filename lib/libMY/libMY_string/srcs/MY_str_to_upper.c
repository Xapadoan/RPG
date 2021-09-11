#include "../includes/MY_str_to_upper.h"

void	MY_str_to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
		i++;
	}
}
