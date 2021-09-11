#include "../includes/MY_str_capitalize.h"

int	MY_str_capitalize(char *str, char delim)
{
	int i;

	i = 0;
	if (!str) {
		fputs("Warning : No string to capitalize\n", stderr);
		return (1);
	}

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	while (str[i] != '\0') {
		if (str[i] == delim) {
			if (str[i + 1] <= 'z' && str[i + 1] >= 'a')
				str[i + 1] -= 32;
			str[i] = ' ';
		} else if (i > 0 && str[i - 1] != ' ') {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}

	return (1);
}
