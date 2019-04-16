#include "../includes/loadCharacterSprite.h"

int	loadCharacterSprite(Character *character) {
	char *sprite_name;

	sprite_name = NULL;
	sprite_name = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 1) * sizeof(char));
	if (!sprite_name) {
		fputs("Memory Error : Failed to allocate memory for sprite_name\n", stderr);
		return (0);
	}
	MY_str_append(sprite_name, CHARACTER_SPRITE_PATH);

	switch (character->race) {
		case (CORAN) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 8) * sizeof(char));
			MY_str_append(sprite_name, "coran_");
			break;
		case (HUMAN) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 8) * sizeof(char));
			MY_str_append(sprite_name, "human_");
			break;
		case (SANAK) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 8) * sizeof(char));
			MY_str_append(sprite_name, "sanak_");
			break;
		case (ELF) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 6) * sizeof(char));
			MY_str_append(sprite_name, "elf_");
			break;
		case (FAIRY) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 8) * sizeof(char));
			MY_str_append(sprite_name, "fairy_");
			break;
		case (DWARF) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 8) * sizeof(char));
			MY_str_append(sprite_name, "dwarf_");
			break;
		default :
			fputs("Error : Unknown race\n", stderr);
			return (0);
			break;
	}

	if (character->gender)
		MY_str_append(sprite_name, "f");
	else
		MY_str_append(sprite_name, "m");

	switch (character->dir) {
		case (UP) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 6) * sizeof(char));
			MY_str_append(sprite_name, "back_");
			break;
		case (DOWN) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 6) * sizeof(char));
			MY_str_append(sprite_name, "face_");
			break;
		case (LEFT) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 6) * sizeof(char));
			MY_str_append(sprite_name, "left_");
			break;
		case (RIGHT) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 7) * sizeof(char));
			MY_str_append(sprite_name, "right_");
			break;
		default :
			fputs("Error : Unknow direction\n", stderr);
			return (0);
			break;
	}

	switch (character->state) {
		case (CHARACTER_STATE_WALKING) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 13) * sizeof(char));
			MY_str_append(sprite_name, "walking2.png");
			if (character->sprite2)
				SDL_FreeSurface(character->sprite2);
			character->sprite2 = IMG_Load(sprite_name);
			if (!character->sprite2) {
				fprintf(stderr, " Error : Failed to load second sprite for walking\n\t%s\n", sprite_name);
				return (0);
			}

			if (character->dir & (LEFT | RIGHT)) {
				sprite_name[MY_str_len(sprite_name) - 5] = '3';
				if (character->sprite3)
					SDL_FreeSurface(character->sprite3);
				character->sprite3 = IMG_Load(sprite_name);
				if (!character->sprite3) {
					fprintf(stderr, "Error : Failed to load second sprite for walking\n\t%s\n", sprite_name);
					return (0);
				}
			} else if (character->sprite3) {
				SDL_FreeSurface(character->sprite3);
				character->sprite3 = NULL;
			}

			sprite_name[MY_str_len(sprite_name) - 5] = '1';
			sprite_name[MY_str_len(sprite_name) - 4] = '\0';
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 1) * sizeof(char));
			break;
		case (CHARACTER_STATE_STANDING) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 9) * sizeof(char));
			MY_str_append(sprite_name, "standing");
			break;
		case (CHARACTER_STATE_SITTED) :
			sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 7) * sizeof(char));
			MY_str_append(sprite_name, "sitted");
			break;
		default :
			fprintf(stderr, "Warning : Unknown state (%x)\n", character->state);
	}

	sprite_name = (char *)realloc(sprite_name, (MY_str_len(sprite_name) + 5) * sizeof(char));
	MY_str_append(sprite_name, ".png");

	if (character->sprite != NULL)
		SDL_FreeSurface(character->sprite);

	character->sprite = IMG_Load(sprite_name);

	if (!character->sprite) {
		fprintf(stderr, "Warning : Loading character sprite '%s' failed\n", sprite_name);
		free(sprite_name);
		return (0);
	}

	free(sprite_name);
	return (1);
}
