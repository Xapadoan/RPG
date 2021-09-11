#include "../includes/MY_str2hex.h"

unsigned int	MY_str2hex(const char *str) {
	unsigned int hex;
	int i;

	i = 0;
	hex = 0;
	if (!str)
		return (0);

	if (str[1] == 'x' || str[1] == 'X')
		i = 2;

	while (str[i]) {
		hex *= 16;
		if ('0' <= str[i] && str[i] <= '9')
			hex += str[i] - '0';
		else if ('a' <= str[i] && str[i] <= 'f')
			hex += str[i] - 'a';
		else if ('A' <= str[i] && str[i] <= 'F')
			hex += str[i] - 'A';
		i++;
	}

	return (hex);
}
