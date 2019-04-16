#include "../includes/loadMapTexture.h"

SDL_Surface	*loadMapTexture(int tex){
	SDL_Surface *texture;
	int i = 0;
	char line[50];
	FILE *file;
	char *texture_name;

	file = NULL;
	texture = NULL;
	texture_name = NULL;

	file = fopen("resource/info/background/background_textures.def", "r");
	if (!file){
		fputs("File Error : Can't open background_textures.def\n", stderr);
		return (NULL);
	}

	while (i++ <= tex)
		fgets(line, 50, file);
	i = 0;
	while (line[++i] != '\n');
	line[i] = '\0';

	texture_name = (char *)calloc(1, (MY_str_len(TEXTURES_PATH_BACKGROUND) + MY_str_len(line) + 1) * sizeof(char));
	MY_str_append(texture_name, TEXTURES_PATH_BACKGROUND);
	MY_str_append(texture_name, line);

	texture = IMG_Load(texture_name);
	if (!texture){
		fputs("IMG Error : Can't load texture '", stderr);
		fputs(line, stderr);
		fputs("'\n", stderr);
		fputs("Search in : '", stderr);
		fputs(TEXTURES_PATH_BACKGROUND, stderr);
		fputs("'\n", stderr);
		return (NULL);
	}

	fclose(file);
	free(texture_name);

	return (texture);
}
