#include "../includes/MY_remove_char.h"

char	*MY_remove_char(char *src, char c, int free_str)
{
	int i;
	int j;
	char *res;

	i = 0;
	j = 0;
	res = NULL;

	while (src[i] != '\0') {
		if (src[i] != c)
			j++;
		i++;
	}
	res = (char *)malloc((j + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!res) {
		write(2, "Memory Error : Malloc failed\n", 29);
		return (NULL);
	}

	while(src[i] != '\0') {
		if (src[i] != c)
			res[j++] = src[i];
		i++;
	}
	res[j] = '\0';

	if (free_str)
		free(src);
	return (res);
}
