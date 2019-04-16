#include "../includes/loadItemContainerItems.h"

int	loadItemContainerItems(MapItem *container, const char *map_name)
{
	char *path;
	char *container_id;
	FILE *file;

	file = NULL;
	path = NULL;
	container_id = NULL;
	//If map item is not a container ends normally
	if (!isItemContainer(container))
		return (1);

	//Create string container_id to store (char *)hex(container->id)
	container_id = MY_hex2char(container->id);
	if (!container_id) {
		fputs("Error : Failed to convert hexadecimal to char\n", stderr);
		return (0);
	}

	//Create item list path
	path = (char *)calloc(1, (MY_str_len(MAP_PATH) + MY_str_len(map_name) + MY_str_len(container->name) + MAP_ITEM_CONTAINER_ID_LEN + 7) * sizeof(char));
	if (!path) {
		fputs("Error : Failed to allocate memory for item list path\n", stderr);
		free(container_id);
		return (0);
	}

	MY_str_append(path, MAP_PATH);
	MY_str_append(path, map_name);
	MY_str_append(path, "/");
	MY_str_append(path, container->name);
	MY_str_append(path, "_");
	MY_str_append(path, container_id);
	MY_str_append(path, ".itm");

	//Open item list file
	file = fopen(path, "r");
	if (!file) {
		fprintf(stderr, "File Error : Failed to open item list\n\t'%s'\n", path);
		free(path);
		free(container_id);
		return (0);
	}

	//Load item bag
	if (!loadItemBag(container->items, file)) {
		fputs("Error : Failed to load item bag\n", stderr);
		return (0);
	}

	//Normal end
	fclose(file);
	free(path);
	free(container_id);
	return (1);
}
