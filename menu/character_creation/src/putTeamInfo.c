#include "../includes/putTeamInfo.h"

int	putTeamInfo(SDL_Surface *dest, TTF_Font *font, Character team[4])
{
	SDL_Rect pos;
	unsigned int i;

	pos.x = CHARACTER_MENU_DIMENSION_MARGIN + 2;
	pos.y = CHARACTER_MENU_DIMENSION_MARGIN - 2;
	i = 0;
	if (!font)
		fputs("Warning : Font for character preview is not loaded\n", stderr);

	while (team[i].confirmed) {
		if (!putCharacterPreview(dest, font, &team[i], &pos)) {
			fputs("Warning : Can't put character preview\n", stderr);
			return (0);
		}
		pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
		i++;
	}

	return (1);
}
