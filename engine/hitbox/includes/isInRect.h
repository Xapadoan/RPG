#ifndef DEF_IS_IN_RECT
#define DEF_IS_IN_RECT

#include <SDL/SDL.h>

int	isInRect(int x, int y, SDL_Rect *rect);
int	crossY(SDL_Rect *rect1, SDL_Rect *rect2);
int	crossX(SDL_Rect *rect1, SDL_Rect *rect2);

#endif
