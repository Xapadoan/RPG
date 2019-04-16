#include "../includes/MY_clear_string.h"

void MY_clear_string(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i++] != '\0')
		str[i - 1] = 0;
}
