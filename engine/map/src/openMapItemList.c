#include "../includes/openMapItemList.h"

FILE	*openMapItemList(const char *map_name)
{
	FILE *file;
	char *path;

	file = NULL;
	path = NULL;

	//Builds map item list path
	path = (char *)calloc(1, (MY_str_len(MAP_PATH) + 2 * MY_str_len(map_name) + 7) * sizeof(char));
	if (!path) {
		fputs("Memory Error : Failed to allocate memory for map items list path\n", stderr);
		return (NULL);
	}
	MY_str_append(path, MAP_PATH);
	MY_str_append(path, map_name);
	MY_str_append(path, "/");
	MY_str_append(path, map_name);
	MY_str_append(path, ".mitm");

	//Tries to open the file
	file = fopen(path, "r");
	if (!file) {
		fprintf(stderr, "File Error : Failed to open map item list :\n\
				\tMap \"%s\"", map_name);
		return (NULL);
	}

	free(path);
	return (file);
}
