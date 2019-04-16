#include "../includes/putCCMBoxes.h"

int	putCCMBoxes(SDL_Surface *screen, SDL_Surface *menu, Character team[4], const unsigned int i, const unsigned int choice)
{
	SDL_Rect pos;
	TTF_Font *font;

	font = NULL;
	pos.x = 350;
	pos.y = (2 * CHARACTER_MENU_DIMENSION_MARGIN)\
			+ ((CHARACTER_MENU_DIMENSION_HEIGHT_BOX - FONT_CHARACTER_CREATION_SIZE) / 2);

	font = TTF_OpenFont(FONT_CHARACTER_CREATION_TYPE, FONT_CHARACTER_CREATION_SIZE);
	if (!font) {
		fputs("TTF Error : Can't open font for character creation menu\n", stderr);
		return (0);
	}

	SDL_BlitSurface(menu, NULL, screen, NULL);
	if (!putTeamInfo(screen, font, team))
		fputs("Warning : Can't put team info\n", stderr);

	if (!putGender(screen, font, team[i].gender, &pos)) {
		fputs("Warning : Can't put character's gender\n", stderr);
		return (0);
	}

	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
	if (!putRace(screen, font, team[i].race, &pos)) {
		fputs("Error : Can't put race\n", stderr);
		return (0);
	}

	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
	if (team[i].name != NULL && MY_str_len(team[i].name) > 0) {
		if (!putName(screen, font, team[i].name, &pos)) {
			fputs("Error : Can't put name\n", stderr);
			return (0);
		}
	}

	pos.y += CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_HEIGHT_BOX;
	if (!putConfirm(screen, font, &pos)) {
		fputs("Error : Can't put confirm\n", stderr);
		return (0);
	}

	putUserInfo(screen, font, choice);
	TTF_CloseFont(font);
	return (1);
}
