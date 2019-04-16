#include "../includes/loadTabPreviewIcon.h"

SDL_Surface	*loadTabPreviewIcon(const char *name)
{
	SDL_Surface *icon;
	char *path;

	path = NULL;
	icon = NULL;
	path = (char *)calloc(1, (MY_str_len(MENU_TABS_PREVIEW_ICON_PATH) + MY_str_len(name) + 5) * sizeof(char));
	if (!path) {
		fputs("Memory Error : Failed to allocate memory for icon path\n", stderr);
		return (NULL);
	}

	MY_str_append(path, MENU_TABS_PREVIEW_ICON_PATH);
	MY_str_append(path, name);
	MY_str_append(path, ".png");

	icon = IMG_Load(path);
	if (!icon) {
		fprintf(stderr, "IMG Error : Failed to load tab preview icon :\n\t%s\n", path);
		free(path);
		return (NULL);
	}

	free(path);
	return (icon);
}
