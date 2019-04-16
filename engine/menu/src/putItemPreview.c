#include "../includes/putItemPreview.h"

int	putItemPreview(SDL_Surface *dest, const char *item_str) {
	SDL_Surface *item_preview;
	SDL_Rect preview_pos;
	char **item_info;
	char *path;

	path = NULL;
	item_info = NULL;
	item_preview = NULL;
	preview_pos.y = MENU_ITEM_PREVIEW_BORDERS_WIDTH + MENU_ITEM_PREVIEW_MARGIN;

	if (!dest | !item_str) {
		fputs("Arg Error : Missing arguments for putItemPreview\n", stderr);
		return (0);
	}

	item_info = MY_str_split(item_str, ";");
	if (!item_info) {
		fprintf(stderr, "Error : Failed to split string :\n\t%s\t(%s)\n", item_str, ";");
		return (0);
	}

	switch(MY_str2hex(item_info[1])) {
		case (ITEM_CATEGORY_POTION) :
			path = (char *)calloc(1, (MY_str_len(ITEM_POTION_PATH) + 2 * MY_str_len(item_info[0]) + 6) * sizeof(char));
			if (!path) {
				fputs("Memory Error : Failed to allocate memory for potion preview path\n", stderr);
				return (0);
			}
			MY_str_append(path, ITEM_POTION_PATH);
			MY_str_append(path, item_info[0]);
			MY_str_append(path, "/");
			MY_str_append(path, item_info[0]);
			MY_str_append(path, ".png");
			break;
		case (ITEM_CATEGORY_ARMOR) :
			path = (char *)calloc(1, (MY_str_len(ITEM_POTION_PATH) + 2 * MY_str_len(item_info[0]) + 6) * sizeof(char));
			if (!path) {
				fputs("Memory Error : Failed to allocate memory for potion preview path\n", stderr);
				return (0);
			}
			MY_str_append(path, ITEM_ARMOR_PATH);
			MY_str_append(path, item_info[0]);
			MY_str_append(path, "/");
			MY_str_append(path, item_info[0]);
			MY_str_append(path, ".png");
			break;
		case (ITEM_CATEGORY_WEAPON) :
			path = (char *)calloc(1, (MY_str_len(ITEM_POTION_PATH) + 2 * MY_str_len(item_info[0]) + 6) * sizeof(char));
			if (!path) {
				fputs("Memory Error : Failed to allocate memory for potion preview path\n", stderr);
				return (0);
			}
			MY_str_append(path, ITEM_WEAPON_PATH);
			MY_str_append(path, item_info[0]);
			MY_str_append(path, "/");
			MY_str_append(path, item_info[0]);
			MY_str_append(path, ".png");
			break;
		case (ITEM_CATEGORY_BOOK) :
			path = (char *)calloc(1, (MY_str_len(ITEM_POTION_PATH) + 2 * MY_str_len(item_info[0]) + 6) * sizeof(char));
			if (!path) {
				fputs("Memory Error : Failed to allocate memory for potion preview path\n", stderr);
				return (0);
			}
			MY_str_append(path, ITEM_BOOK_PATH);
			MY_str_append(path, item_info[0]);
			MY_str_append(path, "/");
			MY_str_append(path, item_info[0]);
			MY_str_append(path, ".png");
			break;
		case (ITEM_CATEGORY_MISC) :
			path = (char *)calloc(1, (MY_str_len(ITEM_POTION_PATH) + 2 * MY_str_len(item_info[0]) + 6) * sizeof(char));
			if (!path) {
				fputs("Memory Error : Failed to allocate memory for potion preview path\n", stderr);
				return (0);
			}
			MY_str_append(path, ITEM_MISC_PATH);
			MY_str_append(path, item_info[0]);
			MY_str_append(path, "/");
			MY_str_append(path, item_info[0]);
			MY_str_append(path, ".png");
			break;
		default :
			fprintf(stderr, "Error : Unkonwn item category (%s)\n", item_info[1]);
			return (0);
			break;
	}

	item_preview = IMG_Load(path);
	if (!item_preview) {
		fprintf(stderr, "IMG Error : Failed to load item preview :\n\t%s\n", path);
		return (0);
	}
	preview_pos.w = item_preview->w;
	preview_pos.h = item_preview->h;
	preview_pos.x = MENU_ITEM_PREVIEW_BORDERS_WIDTH + (dest->w - preview_pos.w) / 2;

	SDL_BlitSurface(item_preview, NULL, dest, &preview_pos);

	MY_free_2d_char(item_info);
	SDL_FreeSurface(item_preview);
	free(path);
	return (1);
}
