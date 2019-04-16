#include "../includes/loadYMap.h"

SDL_Surface	*loadYMap(const char *map_path){
	SDL_Surface *map;
	FILE *map_file;
	char line[200];
	SDL_Rect area;
	SDL_Rect dim;

	area.x = 0;
	area.y = 0;
	area.w = 0;
	area.h = 0;
	map_file = NULL;
	map = NULL;

	map_file = fopen(map_path, "r");
	if (!map_file){
		fputs("File Error : Can't open map file\n", stderr);
		return (NULL);
	}

	dim = getMapDimensions(map_file);
	if (dim.w == 0 || dim.h == 0)
		return (NULL);

	map = SDL_CreateRGBSurface(SDL_HWSURFACE, dim.w, dim.h, 32, 0, 0, 0, 0);
	if (!map){
		fputs("SDL Error : Can't create RGB Surface\n", stderr);
		return (NULL);
	}

	while(fgets(line, 200, map_file)){
		loadMapLine(map, line, &area);
	}

	fclose(map_file);
	return (map);
}

SDL_Rect	getMapDimensions(FILE *map_file){
	SDL_Rect dim;
	char line[200];
	char clen[3];
	char cheight[3];

	dim.w = 0;
	dim.h = 0;

	if (fgets(line, MAP_SIZE_BIT, map_file)){
		clen[0] = line[0];
		clen[1] = line[1];
		clen[2] = line[2];
		clen[3] = '\0';
		cheight[0] = line[3];
		cheight[1] = line[4];
		cheight[2] = line[5];
		cheight[3] = '\0';

		dim.w = MY_hex2dec(clen);
		dim.h = MY_hex2dec(cheight);
	}

	return (dim);
}
