#include "../includes/MY_str_len.h"

int	MY_str_len(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i++] != '\0');
	return (--i);
}
