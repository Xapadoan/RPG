#include "../includes/putClosedEyes.h"

int	putClosedEyes(Character *character, SDL_Surface *surf, SDL_Rect *character_pos)
{
	SDL_Surface *eyes;
	SDL_Rect pos;
	char *eyes_path;

	eyes = NULL;
	eyes_path = NULL;
	pos.w = CHARACTER_SPRITE_EYES_WIDTH;
	pos.h = CHARACTER_SPRITE_EYES_HEIGHT;
	switch (character->race) {
		case (CORAN) :
			pos.x = character_pos->x + CHARACTER_SPRITE_CORAN_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_CORAN_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 22) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "coran_eyes_closed.png");
			break;
		case (DWARF) :
			pos.x = character_pos->x + CHARACTER_SPRITE_DWARF_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_DWARF_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 22) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "dwarf_eyes_closed.png");
			break;
		case (ELF) :
			pos.x = character_pos->x + CHARACTER_SPRITE_ELF_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_ELF_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 20) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "elf_eyes_closed.png");
			break;
		case (FAIRY) :
			pos.x = character_pos->x + CHARACTER_SPRITE_FAIRY_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_FAIRY_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 22) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "fairy_eyes_closed.png");
			break;
		case (HUMAN) :
			pos.x = character_pos->x + CHARACTER_SPRITE_HUMAN_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_HUMAN_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 22) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "human_eyes_closed.png");
			break;
		case (SANAK) :
			pos.x = character_pos->x + CHARACTER_SPRITE_SANAK_EYES_X;
			pos.y = character_pos->y + CHARACTER_SPRITE_SANAK_EYES_Y;
			eyes_path = (char *)calloc(1, (MY_str_len(CHARACTER_SPRITE_PATH) + 22) * sizeof(char));
			MY_str_append(eyes_path, CHARACTER_SPRITE_PATH);
			MY_str_append(eyes_path, "sanak_eyes_closed.png");
			break;
		default :
			fputs("Warning : Unknown race\n", stderr);
			return (0);
			break;
	}

	if (!eyes_path) {
		fputs("Memory Error : Failed to allocate memory for eyes path\n", stderr);
		return (0);
	}

	eyes = IMG_Load(eyes_path);
	if (!eyes) {
		fputs("IMG Error : Failed to load closed eyes sprite\n", stderr);
		return (0);
	}

	SDL_BlitSurface(eyes, NULL, surf, &pos);
	SDL_FreeSurface(eyes);
	free(eyes_path);

	return (1);
}
