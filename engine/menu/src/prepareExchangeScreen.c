#include "../includes/prepareExchangeScreen.h"

SDL_Surface	*prepareExchangeScreen(char *container_name, SDL_Surface *screen)
{
	SDL_Surface *background;
	SDL_Surface *container_background;
	char *container_background_path;

	background = NULL;
	container_background = NULL;
	container_background_path = NULL;
	if (screen) {
		background = SDL_ConvertSurface(screen, screen->format, SCREEN_FLAGS);
		if (!background) {
			fputs("Warning : Failed to copy screen\n", stderr);
			background = SDL_CreateRGBSurface(SCREEN_FLAGS, SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, SCREEN_COLORS_DEPTH, 0, 0, 0, 0);
			if (!background) {
				fputs("Error : Failed to create black surface\n", stderr);
				return (NULL);
			}
		}
	} else {
		background = SDL_CreateRGBSurface(SCREEN_FLAGS, SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, SCREEN_COLORS_DEPTH, 0, 0, 0, 0);
		if (!background) {
			fputs("Error : Failed to create black surface\n", stderr);
			return (NULL);
		}
	}

	if (!applyRGBA(background, 0, 0, 0, 150))
		fputs("Warning : Failed to apply RGBA\n", stderr);

	if (!container_name) {
		fputs("Notice : No container name, cannot load container background\n", stderr);
		return (background);
	} else {
		container_background_path = (char *)calloc(1, \
				(MY_str_len(MAP_ITEM_CONTAINER_BACKGROUND_PATH)\
				 + MY_str_len(container_name)\
				 + 16\
				 ) * sizeof(char));
		if (!container_background_path) {
			fputs("Warning : Failed to allocate memory for container background path\n", stderr);
			return (background);
		}
		MY_str_append(container_background_path, MAP_ITEM_CONTAINER_BACKGROUND_PATH);
		MY_str_append(container_background_path, container_name);
		MY_str_append(container_background_path, "_background");
		MY_str_append(container_background_path, ".png");

		container_background = IMG_Load(container_background_path);
		if (!container_background) {
			fprintf(stderr, "Warning : Failed to load container background\n\t%s\n", container_background_path);
			free(container_background_path);
			return (background);
		}

		blitOnCenter(container_background, background);
		SDL_FreeSurface(container_background);
		free(container_background_path);
		return (background);
	}
}
