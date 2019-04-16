#include "../includes/stopPlayingMusic.h"

void	stopPlayingMusic(Mix_Music *music, unsigned int time)
{
	while (!Mix_FadeOutMusic(time) && Mix_PlayingMusic())
		SDL_Delay(50);

	Mix_FreeMusic(music);
	music = NULL;
}
