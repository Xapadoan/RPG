#ifndef DEF_STOP_PLAYING_MUSIC
#define DEF_STOP_PLAYING_MUSIC

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void	stopPlayingMusic(Mix_Music *music, unsigned int time);

#endif
