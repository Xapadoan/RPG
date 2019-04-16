#ifndef DEF_HITBOX
#define DEF_HITBOX

#include <SDL/SDL.h>

typedef struct ElemHitbox {
	SDL_Rect pos;
	struct ElemHitbox *next;
} ElemHitbox;

typedef struct Hitbox {
	unsigned int len;
	ElemHitbox *first;
} Hitbox;

#endif
