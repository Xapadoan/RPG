#include "../includes/MY_hex2str.h"

static int	get_length(unsigned long hex, int field_width)
{
	int	res;

	res = (hex == 0);
	while (hex)
	{
		hex /= 16;
		res++;
	}
	res = (res > field_width ? res : field_width);
	return (res);
}

char		*MY_hex2str(unsigned long hex, int field_width)
{
	char	*res;
	int	len;

	len = get_length(hex, field_width);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	while (len)
	{
		res[--len] = hex % 16 + ((hex % 16 < 10) ? '0' : 'a' - 10);
		hex = (hex - (hex % 16)) / 16;
	}
	return (res);
}
