#include "../includes/MY_str_substr.h"

int	MY_str_substr(const char *src, const char *to_find, unsigned int start)
{
	int i;
	int res;

	i = 0;
	res = start;
	//We find the first character of 'src' matching the first character of the
	//string 'to_find'.
	while (src[res] != '\0' && src[res++] != to_find[0]);
	
	//Then we check if the following characters of 'src' match the following
	//characters of the string 'to_find'.
	//
	//We use an other incrementator to keep track of the firsts characters
	//matching position ('res') if this test fails.
	while (src[res + i] != '\0' && src[res + i] == to_find[i + 1]\
		&& to_find[i + 1] != '\0')
		i++;

	//There are 3 way to exit the previous loop :
	//	- the string 'to_find' is ended, it means that we succedeed in finding
	//		it. We will return the character just before the first matching
	//		one
	//	- the string 'src' is ended, it means that the string 'to_find' is not
	//		in the string 'src'
	//	- the characters following the first matching character are different
	//		in the strings 'src' and 'to_find'. The string 'to_find' may be
	//		in the 'src' after that, so we rerun the function starting by the
	//		character following the first matching character.
	if (to_find[i + 1] == '\0' && src[res] != '\0') {
		return (res - 1);
	}
	else if (src[res] == '\0')
		return (-1);
	else
		return (MY_str_substr(src, to_find, res));
}
