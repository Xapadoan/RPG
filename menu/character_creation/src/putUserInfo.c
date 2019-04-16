#include "../includes/putUserInfo.h"

void	putUserInfo(SDL_Surface *dest, TTF_Font *font, const unsigned int choice)
{
	FILE *file;
	unsigned int i;
	char info[70];
	SDL_Color color;
	SDL_Rect pos;

	file = NULL;
	i = 0;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	pos.x = CHARACTER_MENU_DIMENSION_MARGIN + 4;
	pos.y = (CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX) * 5;

	file = fopen("resource/info/charact_creation_user_help.txt", "r");
	if (!file)
		fputs("File Warning : Can't open file for user info\n", stderr);

	do {
		fgets(info, 70, file);
	} while (i++ < choice);

	putFontColumn(font, info, color, dest, &pos, 2 * CHARACTER_MENU_DIMENSION_WIDTH_BOX / TTF_FontHeight(font));
	fclose(file);
}
