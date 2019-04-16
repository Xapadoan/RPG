#include "../includes/chooseConfirm.h"

int	chooseConfirm(SDL_Rect *pos, SDL_KeyboardEvent *key, unsigned int *choice)
{
	switch(key->keysym.sym)
	{
		case (SDLK_RIGHT) :
			if (pos->x < 250)
			pos->x += 270;
			break;
		case (SDLK_LEFT) :
			if (pos->x > 250)
				pos->x -= 270;
			break;
		case (SDLK_ESCAPE) :
			*choice = 2;
			return (1);
			break;
		case (SDLK_e) :
		case (SDLK_RETURN) :
			if (pos->x < 250)
				*choice = 1;
			else
				*choice = 2;
			return (1);
			break;
		default :
			fputs("Warning : Abscisse value is not valid\n", stderr);
			break;
	}
	return (0);
}
