#include "../includes/MY_str_replace.h"

void	MY_str_replace(char *str1, const char *str2, int beg)
{
	int i;

	i = beg;
	while ((str1[i] != '\0') && (str2[i - beg] != '\0')) {
		str1[i] = str2[i - beg];
		i++;
	}
}
