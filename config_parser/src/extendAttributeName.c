#include "../includes/extendAttributeName.h"

char	*extendAttributeName(char *attribute_name, char *to_add)
{
	attribute_name = realloc(attribute_name, (MY_str_len(attribute_name) + MY_str_len(to_add)) * sizeof(char));
	MY_str_to_upper(to_add);
	to_add[MY_str_len(to_add) - 2] = '_';
	to_add[MY_str_len(to_add) - 1] = '\0';
	MY_str_append(attribute_name, to_add);

	return (attribute_name);
}
