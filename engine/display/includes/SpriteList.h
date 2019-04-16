#ifndef DEF_SPRITE_LIST
#define DEF_SPRITE_LIST

#include <SDL/SDL.h>

typedef struct ElemSpriteList {
	int x;
	int y;
	SDL_Surface *sprite;
	struct ElemSpriteList *next;
} ElemSpriteList;

typedef struct SpriteList {
	ElemSpriteList *first;
	int len;
} SpriteList;

#endif
