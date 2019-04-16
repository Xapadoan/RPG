#include "../includes/showRaceDescription.h"

void	showRaceDescription(TTF_Font *font, SDL_Surface *dest, const unsigned int race)
{
	SDL_Rect pos;

	pos.x = CHARACTER_MENU_DIMENSION_MARGIN + 4;
	pos.y = CHARACTER_MENU_DIMENSION_MARGIN + 4;
	putRaceInfo(font, dest, &pos, race);
	pos.x = 2 * CHARACTER_MENU_DIMENSION_MARGIN + CHARACTER_MENU_DIMENSION_RACE_WIDTH + 4;
	putRaceSkillsInfo(font, dest, &pos, race);
}
