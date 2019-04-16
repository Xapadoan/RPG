#include "../includes/initEngine.h"

int	initEngine(int sdl_flags, int img_flags, int mix_flags)
{
	int img_initted;
	int mix_initted;

	img_initted = 0;
	mix_initted = 0;
	//Initialisation of SDL
	if (!SDL_Init(sdl_flags) == 0) {
		fputs("SDL Error : Can't init SDL\n", stderr);
		return (0);
	}
	//Initialisation of SDL_image
	img_initted = IMG_Init(img_flags);
	if ((img_initted & img_flags) != img_flags) {
		fputs("IMG Error : Can't init SDL_image\n", stderr);
		return (0);
	}
	//Initialisation of SDL_ttf
	if (TTF_Init() == -1) {
		fputs("TTF Error : Can't init SDL_ttf\n", stderr);
		return (0);
	}
	//Initialisation of SDL_mixer
	mix_initted = Mix_Init(mix_flags);
	if ((mix_initted & mix_flags) != mix_flags) {
		fputs("MIX Error : Can't init SDL_mixer\n", stderr);
		fputs(Mix_GetError(), stderr);
		return (0);
	}

	//Sets the mixer
	if (!(SDL_WasInit(SDL_INIT_AUDIO) == SDL_INIT_AUDIO))
		if (!SDL_Init(SDL_INIT_AUDIO) == 0) {
			fputs("SDL Error : Can't init audio\n", stderr);
			return (0);
		}
	if (Mix_OpenAudio(ENGINE_MIXER_FREQUENCY, ENGINE_MIXER_FORMAT, ENGINE_MIXER_CHANNELS, ENGINE_MIXER_CHUNKSIZE) == -1) {
		fputs("MIX Error : Can't open audio\n", stderr);
		return (0);
	}
	return (1);
}
