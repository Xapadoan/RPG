#include "../includes/MY_str_compare.h"

int	MY_str_compare(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (MY_str_len(str1) != MY_str_len(str2))
		return (0);
	while(str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (i == MY_str_len(str1));
}
