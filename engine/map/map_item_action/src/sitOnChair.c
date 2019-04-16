#include "../includes/sitOnChair.h"

int	sitOnChair(MapItem *self, Map *map, Team *team, SDL_Surface *screen, char **argv)
{
	int i;
	FILE *file;
	char *sprite_full;
	char sprite_name[29];
	SDL_Surface *back_sprite;
	SDL_Rect back_pos;

	i = 0;
	sprite_full = NULL;
	back_sprite = NULL;
	file = NULL;
	back_pos.x = 0;
	back_pos.y = 0;
	back_pos.w = 0;
	back_pos.h = 0;
	if (argv || screen)

	if (!map || !team) {
		fputs("Error : Some arguments are missing\n", stderr);
		return (0);
	}

	while (i < 4)
		team->heroes[i++].state = CHARACTER_STATE_SITTED;
	team->heroes[0].interacting_item = self;
	team->heroes[0].dir = self->dir;

	if (!loadSittedSprite(&(team->heroes[0]), self)) {
		fputs("Error : Failed to load character sitted sprite\n", stderr);
		return (0);
	}

	team->location.x = self->pos.x + self->pos.w / 2;
	team->location.y = self->pos.y + self->pos.h / 2 - (team->heroes[0].sprite->h - self->pos.h + 1) / 2;

	if (self->dir != UP) {
		return (1);
	}

	//If the chair is oriented to the top, we need to put the chair's back
	//
	//First we open the map item list
	file = openMapItemList(team->location.map_name);
	if (!file) {
		fputs("File Error : Failed to open map items list\n", stderr);
		return (0);
	}

	//Go to the line with back sprite name
	if (!searchItemInList(file, self)) {
		fputs("Warning : Failed to find chair in item list\n", stderr);
		return (0);
	}
	MY_go_to_next_line(file);
	fgets(sprite_name, 28, file);

	//Gets the sprite's full path
	sprite_full = (char *)calloc(1, (MY_str_len(MAP_ITEM_PATH) + MY_str_len(self->name) + 31) * sizeof(char));
	if (!sprite_full) {
		fputs("Memory Error : Failed to allocate memory for chair's back sprite\n", stderr);
		fclose(file);
		return (0);
	}
	MY_str_append(sprite_full, MAP_ITEM_PATH);
	MY_str_append(sprite_full, self->name);
	MY_str_append(sprite_full, "/");
	MY_str_append(sprite_full, sprite_name);

	//Tries to load sprite
	back_sprite = IMG_Load(sprite_full);
	if (!back_sprite) {
		fprintf(stderr, "IMG Error : Failed to load chair's back sprite :\n\t%s\n", sprite_full);
		free(sprite_full);
		fclose(file);
		return (0);
	}
	back_pos.x = (team->heroes[0].sprite->w - back_sprite->w) / 2;
	back_pos.y = team->heroes[0].sprite->h - back_sprite->h - MAP_ITEM_SPRITE_MARK_CHAIR_BACK_BOTTOM;
	back_pos.w = back_sprite->w;
	back_pos.h = back_sprite->h;

	SDL_BlitSurface(back_sprite, NULL, team->heroes[0].sprite, &back_pos);

	//team->heroes[0].interacting_item = self;
	//team->heroes[0].state = CHARACTER_STATE_SITTED;

	fclose(file);
	free(sprite_full);
	SDL_FreeSurface(back_sprite);
	return (1);
}

int	loadSittedSprite(Character *character, MapItem *chair)
{
	int	butt_y;
	SDL_Surface *new_sprite;
	SDL_Rect dimension;
	SDL_Rect chair_pos;
	SDL_Rect character_pos;

	butt_y = 0;
	new_sprite = NULL;
	dimension.x = 0;
	dimension.y = 0;
	dimension.w = 0;
	dimension.h = 0;
	chair_pos.x = 0;
	chair_pos.y = 0;
	chair_pos.w = 0;
	chair_pos.h = 0;
	character_pos.x = 0;
	character_pos.y = 0;
	character_pos.w = 0;
	character_pos.h = 0;

	if (!loadCharacterSprite(character)) {
		fputs("Warning : Failed to load character sprite\n", stderr);
		return (0);
	}

	//If no item or no item sprite, the character will just sit down on the
	//floor where he is
	if (!chair || !chair->sprite)
		return (1);

	//Select correct butt relative height
	switch (character->race) {
		case (CORAN) :
			butt_y = CHARACTER_SPRITE_CORAN_BUTT_Y;
			break;
		case (DWARF) :
			butt_y = CHARACTER_SPRITE_DWARF_BUTT_Y;
			break;
		case (ELF) :
			butt_y = CHARACTER_SPRITE_ELF_BUTT_Y;
			break;
		case (FAIRY) :
			butt_y = CHARACTER_SPRITE_FAIRY_BUTT_Y;
			break;
		case (HUMAN) :
			butt_y = CHARACTER_SPRITE_HUMAN_BUTT_Y;
			break;
		case (SANAK) :
			butt_y = CHARACTER_SPRITE_SANAK_BUTT_Y;
			break;
		default :
			fputs("Warning : Unknown race\n", stderr);
			break;
	}

	//Setting the new sprite dimensions and positions
	if (chair->sprite->h / 2 >= butt_y) {
		dimension.h = chair->sprite->h;
		dimension.y = chair->sprite->h / 2 - butt_y;
		character_pos.y = chair->sprite->h / 2 - butt_y;
	} else {
		dimension.h = chair->sprite->h / 2 + butt_y;
		dimension.y = butt_y - chair->sprite->h / 2;
		chair_pos.y = butt_y - chair->sprite->h / 2;
	}

	if (character->sprite->w > chair->sprite->w) {
		dimension.w = character->sprite->w;
		dimension.x = (character->sprite->w - chair->sprite->w) / 2;
		chair_pos.x = (character->sprite->w - chair->sprite->w) / 2;
	} else {
		dimension.w = chair->sprite->w;
		dimension.x = (chair->sprite->w - character->sprite->w) / 2;
		character_pos.x = (chair->sprite->w - character->sprite->w) / 2;
	}

	//Create a new surface
	new_sprite = SDL_CreateRGBSurface(CHARACTER_SPRITE_FLAGS, dimension.w, dimension.h, SCREEN_COLORS_DEPTH, 0, 0, 0, 0);
	if (!new_sprite) {
		fputs("Warning : Failed to create new surface for sitted sprite\n", stderr);
		return (0);
	}

	SDL_BlitSurface(chair->sprite, NULL, new_sprite, &chair_pos);
	SDL_BlitSurface(character->sprite, NULL, new_sprite, &character_pos);

	if (SDL_SetColorKey(new_sprite, SDL_SRCCOLORKEY, SDL_MapRGB(new_sprite->format, 0, 0, 0)))
		fputs("Warning : Failed to set transparency for sitted character sprite\n", stderr);

	SDL_FreeSurface(character->sprite);
	character->sprite = SDL_ConvertSurface(new_sprite, new_sprite->format, CHARACTER_SPRITE_FLAGS);
	SDL_FreeSurface(new_sprite);

	return (1);
}
