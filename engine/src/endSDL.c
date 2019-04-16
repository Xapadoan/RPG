#include "../includes/endSDL.h"

void	endSDL(void)
{
	if (TTF_WasInit())
		TTF_Quit();
	IMG_Quit();
	while (Mix_Init(0))
		Mix_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}
