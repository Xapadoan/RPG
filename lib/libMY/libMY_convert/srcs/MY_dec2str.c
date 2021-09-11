#include "../includes/MY_dec2str.h"

char	*MY_dec2str(unsigned int nb)
{
	int i;
	int len;
	char *str;

	len = 0;
	i = 0;
	str = NULL;
	while (nb / MY_pow(10, len++));
	len--;

	if (nb == 0)
		len = 2;

	str = (char *)calloc(1, (len) * sizeof(char));
	if (!str) {
		fputs("Memory Error : Failed to allocate memory for string\n", stderr);
		return (NULL);
	}

	while (i < len - 1) {
		str[i] = '0' + (nb - (nb % MY_pow(10, len - (i + 1)))) / MY_pow(10, len - (i + 1));
		nb -= nb - (nb % MY_pow(10, len - (i + 1)));
		i++;
	}

	return (str);
}
