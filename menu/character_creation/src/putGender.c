#include "../includes/putGender.h"

int	putGender(SDL_Surface *dest, TTF_Font *font, const int gender, SDL_Rect *pos)
{
	SDL_Color white;
	SDL_Rect pos_font;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	pos_font.x = 4 + pos->x;
	pos_font.y = 4 + pos->y;
	switch (gender) {
		case (0) :
			if (!putFont(font, "MALE", white, dest, &pos_font)) {
				fputs("Error : Can't put gender\n", stderr);
				return (0);
			}
			break;
		case (1) :
			if (!putFont(font, "FEMALE", white, dest, &pos_font)) {
				fputs("Error : Can't put gender\n", stderr);
				return (0);
			}
			break;
		default :
			fputs("Error : Unknown gender\n", stderr);
			return (0);
	}
	return (1);
}
