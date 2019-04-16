#include "../includes/MY_hex2dec.h"

int	MY_hex2dec(char *hex){
	int i = 0;
	int len = 0;
	unsigned int res = 0;

	while (hex[++len] != '\0');

	i = len;
	while(i >= 0){
		if (hex[i] >= '0' && hex[i] <= '9')
			res += (hex[i] - '0') * MY_pow(16, len - i);
		if (hex[i] >= 'A' && hex[i] <= 'F')
			res += (10 + hex[i] - 'A') * MY_pow(16, len - i);
		if (hex[i] >= 'a' && hex[i] <= 'f')
			res += (10 + hex[i] - 'a') * MY_pow(16, len - i);
		i--;
	}

	return (res);
}
