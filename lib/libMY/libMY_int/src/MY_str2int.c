#include "../includes/MY_str2int.h"

int	MY_str2int(const char *str)
{
	int	res;
	int i;
	int len;

	res = 48;
	i = 0;
	len = 0;
	if (!str)
		return (0);

	while (str[i++] != '\0');
	len = i;
	i--;

	if (str[0] == '=')
		len--;

	while (i >= 0) {
		if (str[i] == '-') {
			res *= (-1);
			return (res);
		} else
			res += (str[i] - '0') * MY_pow(10, len - (i + 1));
		i--;
	}

	return (res);
}
