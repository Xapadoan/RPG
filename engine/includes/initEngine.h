#ifndef DEF_INIT_ENGINE
#define DEF_INIT_ENGINE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>

#include "../../includes/config/engine.h"

int	initEngine(int sdl_flags, int img_flags, int mix_flags);

#endif
