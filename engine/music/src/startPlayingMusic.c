#include "../includes/startPlayingMusic.h"

Mix_Music	*startPlayingMusic(const char *music_name, int volume)
{
	Mix_Music *music;

	music = NULL;
	music = Mix_LoadMUS(music_name);
	if (!music) {
		fprintf(stderr, "MIX Warning : Can't load music :\n%s\n", Mix_GetError());
		return NULL;
	}
	Mix_VolumeMusic(volume);
	if (Mix_PlayMusic(music, -1))
		fprintf(stderr, "MIX Warning : Can't play music :\n%s\n", Mix_GetError());
	return (music);
}
