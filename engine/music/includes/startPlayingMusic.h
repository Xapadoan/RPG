#ifndef DEF_START_PLAYING_MUSIC
#define DEF_START_PLAYING_MUSIC

#include <stdlib.h>
#include <SDL/SDL_mixer.h>

Mix_Music	*startPlayingMusic(const char *music_name, int volume);

#endif
