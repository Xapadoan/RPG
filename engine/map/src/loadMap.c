#include "../includes/loadMap.h"

int loadMap(Map *map, const char *map_name)
{
	char *map_path;

	map_path = NULL;
	map_path = (char *)calloc(1, (MY_str_len(MAP_PATH) + 2 * MY_str_len(map_name) + 7) * sizeof(char));
	if (!map_path) {
		fputs("Memory Error : Can't allocate memory for map background path\n", stderr);
		return (0);
	}

	//Loading background
	MY_str_append(map_path, MAP_PATH);
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, "/");
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, ".Ymap");

	map->background = loadYMap(map_path);
	if (!map->background) {
		fputs("Error : Can't load map background\n", stderr);
		free(map_path);
		return (0);
	}

	free(map_path);
	map_path = (char *)calloc(1, (MY_str_len(MAP_PATH) + 2 * MY_str_len(map_name) + 7) * sizeof(char));
	if (!map_path) {
		fputs("Memory Error : Can't allocate memory for map structures path\n", stderr);
		return (0);
	}

	MY_str_append(map_path, MAP_PATH);
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, "/");
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, ".stct");
	loadMapStructures(map->background, map_path);

	free(map_path);
	map_path = (char *)calloc(1, (MY_str_len(MAP_PATH) + 2 * MY_str_len(map_name) + 6) * sizeof(char));
	if (!map_path) {
		fputs("Memory Error : Can't allocate memory for map hitbox path\n", stderr);
		return (0);
	}

	MY_str_append(map_path, MAP_PATH);
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, "/");
	MY_str_append(map_path, map_name);
	MY_str_append(map_path, ".htb");

	if (!loadHitbox(map->hitbox, map_path)) {
		fputs("Error : Failed to set hitbox for map structures\n", stderr);
		return (0);
	}

	free(map_path);
	map_path = (char *)calloc(1, (MY_str_len(MAP_PATH) + 2 * MY_str_len(map_name) + 7) * sizeof(char));
	if (!map_path) {
		fputs("Memory Error : Can't allocate memory for map hitbox path\n", stderr);
		return (0);
	}

	if (!loadMapBag(map->items, map_name)) {
		fputs("Error : Failed to load map items\n", stderr);
		return (0);
	}
	free(map_path);
	return (1);
}
