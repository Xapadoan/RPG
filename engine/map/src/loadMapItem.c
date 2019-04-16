#include "../includes/loadMapItem.h"

MapItem	*loadMapItem(FILE *file, const char *map_name)
{
	MapItem	*item;
	int	nb_sprites;
	int i;
	char name[20];
	char rot[4];
	char **splitted_name;

	item = NULL;
	splitted_name = NULL;
	i = 0;
	nb_sprites = 0;

	//Initialization
	item = (MapItem *)malloc(sizeof(*item));
	if (!item) {
		fputs("Memory Error : Failed to allocate memory for map item\n", stderr);
		return (NULL);
	}
	initMapItem(item);

	if (!file)
		fputs("Warning : No Map item list provided\n", stderr);

	//Get Map Item Data
	if (fscanf(file, "%x\t%s\t%hx\t%hx\t%hx\t%hx\t%s\t%d\n",\
				&(item->id),\
				name,\
				&(item->pos.x),\
				&(item->pos.w),\
				&(item->pos.y),\
				&(item->pos.h),\
				rot,\
				&nb_sprites\
				) == EOF) {
		deleteMapItem(item);
		return (NULL);
	}

	//Prepare sprite
	item->sprite = SDL_CreateRGBSurface(MAP_ITEM_SPRITE_FLAGS, item->pos.w, item->pos.h, MAP_ITEM_SPRITE_COLOR_DEPTH, 0, 0, 0, 0);
	if (!item->sprite) {
		fputs("SDL Error : Failed to create surface for map item sprite\n", stderr);
		return (NULL);
	}
	if (SDL_SetColorKey(item->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(item->sprite->format, 0, 0, 0)))
		fputs("SDL Warning : Failed to set transparancy\n", stderr);

	item->name = MY_str_ncopy(name, 0, MY_str_len(name));

	//Load sprite
	loadMapItemSprite(item, file, nb_sprites);
	item->pos.w = item->sprite->w;
	item->pos.h = item->sprite->h;

	//Load Map Item Hitbox
	if (!loadMapItemHitbox(item, rot))
		fputs("Warning : Can't load map item hitbox\n", stderr);

	//Simplify name
	splitted_name = MY_str_split(name, "_");
	while (splitted_name[i + 1] != '\0')
		i++;
	free(item->name);
	item->name = MY_str_ncopy(splitted_name[i], 0, MY_str_len(splitted_name[i]));

	//Link to action
	chooseMapItemAction(item);

	//Set orientation
	switch (MY_str2int(rot)) {
		case (0) :
			item->dir = DOWN;
			break;
		case (90) :
			item->dir = RIGHT;
			break;
		case (180) :
			item->dir = UP;
			break;
		case (270) :
			item->dir = LEFT;
			break;
		default :
			fprintf(stderr, "Warning : Unknown direction (%d)\n", MY_str2int(rot));
			item->dir = DOWN;
			break;
	}

	//Load Items if any
	if (!loadItemContainerItems(item, map_name)) {
		fprintf(stderr, "Error : Failed to load items (%s)\n", item->name);
		return (NULL);
	}

	MY_free_2d_char(splitted_name);
	return (item);
}

int	loadMapItemSprite(MapItem *item, FILE *file, int nb_sprites)
{
	int i;
	SDL_Surface *current;
	SDL_Surface *rot;
	SDL_Rect pos;
	char *sprite_path;
	char sprite_name[MAP_ITEM_NAME_LEN_MAX + 1];
	char *sprite_full;
	int	rad;

	i = 0;
	sprite_path = NULL;
	sprite_full = NULL;
	rot = NULL;
	current = NULL;
	rad = 0;
	pos.x = 0;
	pos.y = 0;
	pos.w = 0;
	pos.h = 0;

	sprite_path = (char *)calloc(1, (MY_str_len(MAP_ITEM_PATH) + MY_str_len(item->name) + 2) * sizeof(char));
	if (!sprite_path) {
		fputs("Memory Error : Failed to allocate memory for map item sprite path\n", stderr);
		return (0);
	}
	MY_str_append(sprite_path, MAP_ITEM_PATH);
	MY_str_append(sprite_path, item->name);
	MY_str_append(sprite_path, "/");
	while (i < nb_sprites && fscanf(file, "%s\t%hx\t%hx\t%d\n", sprite_name, &(pos.x), &(pos.y), &rad) != EOF) {
		sprite_full = (char *)calloc(1, (MY_str_len(sprite_path) + MY_str_len(sprite_name) + 1) * sizeof(char));
		if (!sprite_full) {
			fputs("Memory Error : Failed to allocate memory for map item full name\n", stderr);
			return (0);
		}
		MY_str_append(sprite_full, sprite_path);
		MY_str_append(sprite_full, sprite_name);

		current = IMG_Load(sprite_full);
		if (!current) {
			fputs("IMG Error : Failed to load map item sprite\n", stderr);
			return (0);
		}
		free(sprite_full);
		sprite_full = NULL;
		rot = rotozoomSurface(current, (double)rad, 1.0, 0);
		SDL_BlitSurface(rot, NULL, item->sprite, &pos);
		SDL_FreeSurface(current);
		SDL_FreeSurface(rot);
		i++;
	}
	free(sprite_path);
	return (1);
}

int	loadMapItemHitbox(MapItem *item, const char *rot)
{
	char *path;
	ElemHitbox *current;

	current = NULL;
	path = NULL;
	path = (char *)calloc(1, (MY_str_len(MAP_ITEM_PATH) + 2 * MY_str_len(item->name) + 10) * sizeof(char));
	if (!path) {
		fputs("Memory Error : Failed to allocate menory for map item hitbox path\n", stderr);
		return (0);
	}

	MY_str_append(path, MAP_ITEM_PATH);
	MY_str_append(path, item->name);
	MY_str_append(path, "/");
	MY_str_append(path, item->name);
	MY_str_append(path, "_");
	MY_str_append(path, rot);
	MY_str_append(path, ".htb");

	if (!loadHitbox(item->hitbox, path)) {
		fputs("Error : Failed to load hitbox for map item\n", stderr);
		free(path);
		return (0);
	}

	if (item->hitbox != NULL)
		current = item->hitbox->first;

	//The last element of hitbox is (0, 0) and not a part of the hitbox
	while (current->next != NULL) {
		current->pos.x += item->pos.x;
		current->pos.y += item->pos.y;
		current = current->next;
	}

	free(path);
	return (1);
}
