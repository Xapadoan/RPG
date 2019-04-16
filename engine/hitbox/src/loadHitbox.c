#include "../includes/loadHitbox.h"

int	loadHitbox(Hitbox *hitbox, const char *path)
{
	FILE *file;
	SDL_Rect box;

	file = NULL;
	box.x = 0;
	box.y = 0;
	box.w = 0;
	box.h = 0;
	file = fopen(path, "r");
	if (!file) {
		fputs("File Error : Failed to open hitbox resource file\n", stderr);
		return (0);
	}

	while (fscanf(file, "%hx\t%hx\t%hx\t%hx\n", &(box.x), &(box.w), &(box.y), &(box.h)) != EOF) {
		if (!addToHitbox(hitbox, &box)) {
			fputs("Error : Failed to grow hitbox\n", stderr);
			return (0);
		}
	}

	fclose (file);
	return (1);
}
