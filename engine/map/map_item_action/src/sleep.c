#include "../includes/sleep.h"

int	sleep(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv)
{
	if (argv)
		fputs("Notice : argument provided where none were needed\n", stderr);

	if (!maxCureTeam(team))
		fputs("Warning : Failed to cure team while sleeping\n", stderr);

	if (!sleepAnimation(self, map, team, screen)) {
		fputs("Error : Failed to play sleepling animation\n", stderr);
		return (0);
	}

	return (1);
}

int	sleepAnimation(MapItem *item, Map *map, Team *team, SDL_Surface *screen)
{
	SDL_Surface *self_sprite;
	SDL_Surface *map_surf;
	SDL_Rect character_pos;
	SDL_Rect view;
	SDL_Rect item_view;
	FILE *file;
	char sprite_name[MAP_ITEM_NAME_LEN_MAX + 1];
	char *sprite_path;
	char *sprite_full;

	self_sprite = NULL;
	map_surf = NULL;
	file = NULL;
	sprite_path = NULL;
	sprite_full = NULL;
	//Setting character position in the bed
	character_pos.x = 0 - CHARACTER_SPRITE_MARGIN_LEFT;
	character_pos.y = 0 - CHARACTER_SPRITE_MARGIN_TOP;
	character_pos.w = team->heroes[0].sprite->w;
	character_pos.h = team->heroes[0].sprite->h;
	//Setting the view
	view.x = item->pos.x + item->pos.w / 2 - SCREEN_SIZE_WIDTH / 2;
	view.y = item->pos.y + item->pos.h / 2 - SCREEN_SIZE_HEIGHT / 2;
	view.w = SCREEN_SIZE_WIDTH;
	view.h = SCREEN_SIZE_HEIGHT;
	if (view.x < 0)
		view.x = 0;
	else if (view.x > map->background->w - SCREEN_SIZE_WIDTH)
		view.x = map->background->w - SCREEN_SIZE_WIDTH;

	if (view.y < 0)
		view.y = 0;
	else if (view.y > map->background->h - SCREEN_SIZE_HEIGHT)
		view.y = map->background->h - SCREEN_SIZE_HEIGHT;

	//Setting item view
	item_view.x = view.x - 200;
	item_view.y = view.y;
	item_view.w = view.w;
	item_view.h = view.h;

	//Copying the map's background
	map_surf = SDL_ConvertSurface(map->background, map->background->format, MAP_SPRITE_FLAGS);
	if (!map_surf) {
		fputs("SDL Error : Failed to copy map surface\n", stderr);
		return (0);
	}

	displayMapItems(map_surf, map->items, &item_view);

	//Prepare sprite path
	sprite_path = (char *)calloc(1, (MY_str_len(MAP_ITEM_PATH) + MY_str_len(item->name) + 2) * sizeof(char));
	if (!sprite_path) {
		fputs("Memory Error : Failed to allocate memory for map item path\n", stderr);
		SDL_FreeSurface(map_surf);
		return (0);
	}
	MY_str_append(sprite_path, MAP_ITEM_PATH);
	MY_str_append(sprite_path, item->name);
	MY_str_append(sprite_path, "/");

	file = openMapItemList(team->location.map_name);
	if (!file) {
		fputs("File Error : Can't open map item list file\n", stderr);
		return (0);
	}

	//Search the item in the item list
	do {
		fgets(sprite_name, MY_str_len(item->name) + 1, file);
		MY_go_to_next_line(file);
	} while (MY_str_len(sprite_name) > 1 && !MY_str_compare(item->name, sprite_name));

	//Load Bed structure
	fgets(sprite_name, 18, file);
	MY_go_to_next_line(file);
	sprite_full = (char *)calloc(1, (MY_str_len(sprite_path) + MY_str_len(sprite_name) + 1) * sizeof(char));
	if (!sprite_full) {
		fputs("Memory Error : Failed to allocate memory for map item sprie path\n", stderr);
		free(sprite_path);
		return (0);
	}

	MY_str_append(sprite_full, sprite_path);
	MY_str_append(sprite_full, sprite_name);

	self_sprite = IMG_Load(sprite_full);
	if (!self_sprite) {
		fputs("IMG Error : Failed to load bed structure sprite\n", stderr);
		free(sprite_path);
		free(sprite_full);
		return (0);
	}
	free(sprite_full);

	//Put team members in bed
	team->heroes[0].dir = DOWN;
	team->heroes[1].dir = DOWN;
	updateTeam(team);

	SDL_BlitSurface(team->heroes[0].sprite, NULL, self_sprite, &character_pos);
	character_pos.x = 0 - CHARACTER_SPRITE_MARGIN_LEFT;
	character_pos.y = 0 - CHARACTER_SPRITE_MARGIN_TOP;
	if (!putClosedEyes(&(team->heroes[0]), self_sprite, &character_pos))
		fputs("Warning : failed to put character eyes\n", stderr);
	character_pos.x = self_sprite->w / 2- CHARACTER_SPRITE_MARGIN_LEFT;
	character_pos.y = 0 - CHARACTER_SPRITE_MARGIN_TOP;
	SDL_BlitSurface(team->heroes[1].sprite, NULL, self_sprite, &character_pos);
	character_pos.x = self_sprite->w / 2 - CHARACTER_SPRITE_MARGIN_LEFT;
	character_pos.y = 0 - CHARACTER_SPRITE_MARGIN_TOP;
	if (!putClosedEyes(&(team->heroes[1]), self_sprite, &character_pos))
		fputs("Warning : Failed to put character_eyes\n", stderr);
	//Put bed on the map
	SDL_BlitSurface(self_sprite, NULL, map_surf, &(item->pos));

	fgets(sprite_name, 19, file);
	sprite_full = (char *)calloc(1, (MY_str_len(sprite_path) + MY_str_len(sprite_name) + 1) * sizeof(char));
	if (!sprite_full) {
		fputs("Memory Error : Failed to allocate memory for map item sprie path\n", stderr);
		free(sprite_path);
		return (0);
	}

	MY_str_append(sprite_full, sprite_path);
	MY_str_append(sprite_full, sprite_name);

	SDL_FreeSurface(self_sprite);

	//Put the blanket on the bed
	self_sprite = IMG_Load(sprite_full);
	if (!self_sprite) {
		fputs("IMG Error : Failed to load bed blanket sprite\n", stderr);
		free(sprite_path);
		free(sprite_full);
		SDL_FreeSurface(map_surf);
		return (0);
	}
	SDL_BlitSurface(self_sprite, NULL, map_surf, &(item->pos));
	SDL_BlitSurface(map_surf, &view, screen, NULL);
	SDL_Flip(screen);
	SDL_Delay(2000);

	SDL_FreeSurface(map_surf);
	SDL_FreeSurface(self_sprite);
	free(sprite_path);
	free(sprite_full);

	fclose(file);
	return (1);
}
