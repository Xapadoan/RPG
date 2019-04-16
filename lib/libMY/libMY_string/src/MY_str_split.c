#include "../includes/MY_str_split.h"

char **MY_str_split(const char *str, const char *delim)
{
	char **res;
	char *temp;
	int nb_parts;
	int pos;
	int splits[50];

	temp = NULL;
	res = NULL;
	nb_parts = 1;
	//'pos' is the last position of a part
	pos = MY_str_substr(str, delim, 0);

	//If the 'str' start with the 'delim' string, we remove that part and rerun the function
	if (pos == 0) {
		temp = MY_str_ncopy(str, MY_str_len(delim), MY_str_len(str) - MY_str_len(delim));
		res = MY_str_split(temp, delim);
		free(temp);
		temp = NULL;
		return (res);
	//If the 'delim' was not found in 'str', we return the full 'str' in res[0]
	} else if (pos == -1) {
		res = (char **)calloc(2, sizeof(char *));
		res[0] = MY_str_ncopy(str, 0, MY_str_len(str));
		res[1] = '\0';
		return (res);
	}
	splits[0] = pos;

	//First, we must count the number of parts
	while (pos != -1 && str[pos + 1] != '\0')
	{
		pos = MY_str_substr(str, delim, pos + 1);
		splits[nb_parts] = pos;
		nb_parts++;
	}

	//We allocate memory for an array of strings of size 'nb_parts'
	res = (char **)malloc((nb_parts + 1) * sizeof(char *));
	splits[nb_parts + 1] = '\0';

	pos = 1;
	res[0] = MY_str_ncopy(str, 0, splits[0]);
	while (pos < nb_parts && splits[pos] != -1)
	{
		res[pos] = MY_str_ncopy(str, splits[pos - 1] + MY_str_len(delim), splits[pos] - (splits[pos - 1] + MY_str_len(delim)));
		pos++;
	}
	res[pos] = MY_str_ncopy(str, splits[pos - 1] + MY_str_len(delim), MY_str_len(str) - (splits[pos - 1] + MY_str_len(delim)));
	//If the last part ends by the delimiter, we remove it.
	if (MY_str_substr(res[pos], delim, 0) != -1) {
		temp = MY_str_ncopy(res[pos], 0, MY_str_len(res[pos]));
		free(res[pos]);
		res[pos] = NULL;
		res[pos] = MY_str_ncopy(temp, 0, MY_str_len(temp) - MY_str_len(delim));
		free(temp);
	}
	res[nb_parts] = '\0';

	return (res);
}
