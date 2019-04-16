#include "../includes/MY_hex2char.h"

char	*MY_hex2char(int nb)
{
	char *str;
	int len;
	int i;
	int bit;

	bit = 0;
	len = 0;
	i = 0;
	str = NULL;

	while (nb >> (4 * ++len));

	str = (char *)calloc(1, (len + 1) * sizeof(char));
	if (!str) {
		fputs("Memory error : Failed to allocate memory for hex string\n", stderr);
		return (NULL);
	}

	while (i < len) {
		bit = (nb >> (4 * (len - (i + 1)))) - ((nb >> (4 * (len - i))) << 4);
		if (bit < 10)
			str[i] = '0' + bit;
		else
			str[i] = 'A' + bit - 10;
		i++;
	}

	str[len] = '\0';

	return (str);
}
