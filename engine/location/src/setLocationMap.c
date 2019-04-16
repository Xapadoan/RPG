#include "../includes/setLocationMap.h"

int	setLocationMap(Location *location, const char *map_name)
{
	if (location->map_name) {
		MY_clear_string(location->map_name);
		location->map_name = (char *)realloc(location->map_name, (MY_str_len(map_name) + 1) * sizeof(char));
	} else
		location->map_name = (char *)calloc(1, (MY_str_len(map_name) + 1) * sizeof (char));

	if (!location->map_name) {
		fputs("Memory Error : Failed toreallocate space for map name\n", stderr);
		return (0);
	}

	MY_str_append(location->map_name, map_name);
	return (1);
}
