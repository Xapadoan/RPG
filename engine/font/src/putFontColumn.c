#include "../includes/putFontColumn.h"

void	putFontColumn(TTF_Font *font, const char *text, const SDL_Color color, SDL_Surface *dest, SDL_Rect *pos, const int length)
{
	unsigned int i;
	unsigned int j;
	int pos_y;
	char *piece_of_string;
	char *current_word;

	piece_of_string = NULL;
	current_word = NULL;
	i = 0;
	j = 0;
	pos_y = pos->y;
	piece_of_string = (char *)malloc((length + 1) * sizeof(char));
	current_word = (char *)malloc((length + 1) * sizeof(char));
	piece_of_string[0] = '\0';
	current_word[0] = '\0';
	while (text[i] != '\0') {
		if (text[i] != ' ') {
			current_word[j] = text[i];
			j++;
		} else {
			current_word[j] = '\0';
			if ((MY_str_len(piece_of_string) + MY_str_len(current_word) + 1) < length) {
				MY_str_append(piece_of_string, " ");
				MY_str_append(piece_of_string, current_word);
			} else {
				i -= j + 1;
				if (!putFont(font, piece_of_string, color, dest, pos))
					fputs("Warning : Can't write piece of string (was cutted from text to fit a column\n)\n", stderr);
				pos->y += TTF_FontHeight(font);
				MY_clear_string(piece_of_string);
				piece_of_string[0] = '\0';
			}
			MY_clear_string(current_word);
			current_word[0] = '\0';
			j = 0;
		}
		i++;
	}

	if (!putFont(font, piece_of_string, color, dest, pos))
		fputs("Warning : Can't write piece of string (was cutted from text to fit a column\n)\n", stderr);
	pos->y = pos_y;
	free(piece_of_string);
	free(current_word);
}
