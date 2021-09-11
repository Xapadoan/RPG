#include "../includes/MY_replace_char.h"

char	*MY_replace_char(char *str, char to_replace, char replacer)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] == to_replace)
			str[i] = replacer;
		i++;
	}

	return (str);
}
