#include "../includes/MY_str_ncopy.h"

char	*MY_str_ncopy(const char *str, int begin, int length)
{
	char *res;
	int i;

	res = NULL;
	i = 0;
	res = (char *)malloc((length + 1) * sizeof(char));
	while (i < length && str[begin + i] != '\0')
	{
		res[i] = str[begin + i];
		i++;
	}
	res[i] = '\0';

	return (res);
}
